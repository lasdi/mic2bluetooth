#include "src/hardware/bluetooth/bluetooth.h"
#include "src/hardware/microphone/mic.h"
#include "src/utils/audio_utils.h"

void app_main(void)

{
    const bool mic_inited = mic_init();
    const bool bluetooth_inited = bluetooth_init();
    if (mic_inited && bluetooth_inited)
    {
        mic_read_data();
    }
}