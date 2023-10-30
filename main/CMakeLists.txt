idf_component_register(SRCS 
                        "main.c"
                        "src/hardware/microphone/mic.c" 
                        "src/hardware/bluetooth/bluetooth.c" 
                        "src/hardware/bluetooth/bt_app_core.c"
                        "src/utils/audio_utils.c"
                    
                    INCLUDE_DIRS 
                    "src/hardware/microphone"
                    "src/hardware/bluetooth"
                    "src/utils"
                    "src/"
                    "."
                    REQUIRES nvs_flash
                    REQUIRES bt
                    REQUIRES driver
                    )
                    #REQUIRES spiffs
#spiffs_create_partition_image(storage ../spiffs_data FLASH_IN_PROJECT)