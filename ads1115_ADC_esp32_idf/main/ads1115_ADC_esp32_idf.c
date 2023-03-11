#include <stdio.h>
#include "common.h" //custom macro defined here
void app_main(void) {
i2c_master_init();
while (1) {
     vTaskDelay(3000 / portTICK_PERIOD_MS);
}
}
