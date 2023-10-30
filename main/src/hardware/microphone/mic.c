#include "mic.h"
#include "preferences.h"
#include <driver/i2s.h>
#include "esp_log.h"
#include "audio_utils.h"

Queue queueOut;

int16_t buffer[N_WINDOW_ELEMENTS];

bool mic_init()
{
    i2s_pin_config_t pin_config = {
        .bck_io_num = SCK_PORT,
        .ws_io_num = WS_IO_PORT,
        .data_out_num = I2S_PIN_NO_CHANGE,
        .data_in_num = SD_PORT};

    i2s_config_t i2s_config = {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
        .sample_rate = FRAME_RATE,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
        .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
        .communication_format = I2S_COMM_FORMAT_I2S_MSB,
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
        .dma_buf_count = 4,
        .dma_buf_len = N_WINDOW_ELEMENTS / 2,
        .use_apll = 0,
    };

    esp_err_t err = i2s_driver_install(I2S_NUM, &i2s_config, 0, NULL);
    esp_err_t err2 = i2s_set_pin(I2S_NUM_0, &pin_config);
    esp_err_t err3 = i2s_set_sample_rates(I2S_NUM_0, FRAME_RATE);

    if (err != ESP_OK || err2 != ESP_OK || err3 != ESP_OK)
    {
        ESP_LOGE("MIC", "Failed to install I2S driver (%s)", esp_err_to_name(err));
        return false;
    }

    ESP_LOGI("MIC", "Microphone initialized");
    return true;
}

void mic_read_data()
{

    while (1)
    {
        size_t bytes_read;
        i2s_read(I2S_NUM_0, buffer, N_WINDOW_ELEMENTS, &bytes_read, 10);
        int buffer_samples_read = bytes_read / sizeof(int16_t);
        if (buffer_samples_read > 0)
        {
            for (int i = 0; i < buffer_samples_read; i++)
            {
                enqueue(&queueOut, buffer[i]);
            }
        }
    }
}