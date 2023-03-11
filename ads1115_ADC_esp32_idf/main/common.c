#include "common.h" //custom macro defined here
void i2c_master_init() {
    i2c_config_t i2c_config = {
            .mode = I2C_MODE_MASTER,
            .sda_io_num = SDA_GPIO,
            .scl_io_num = SCL_GPIO,
            .sda_pullup_en = GPIO_PULLUP_ENABLE,
            .scl_pullup_en = GPIO_PULLUP_ENABLE,
            .master.clk_speed = 100000 //i2c frequency of clock
 
    };
    i2c_param_config(I2C_NUM_0, &i2c_config);
    i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0);
 
//*************// Verify that the I2C slave is working properly
   esp_err_t esp_retval;  
 
   i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (I2C_ADDR_PRIM << 1) | I2C_MASTER_WRITE, true);
    i2c_master_stop(cmd);
    esp_retval = i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_PERIOD_MS);
    if (esp_retval != ESP_OK) {
       ESP_LOGI(TAG_ADS1115,"I2C slave NOT working or wrong I2C slave address - error (%i)", esp_retval);
        // LABEL
    } else {
        ESP_LOGI(TAG_ADS1115,"I2C slave is working or I2C slave address good (%x)", I2C_ADDR_PRIM);
    }
i2c_cmd_link_delete(cmd);
 
}

int8_t i2c_reg_read(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length) {
 
    int8_t iError;
    esp_err_t esp_err;
    i2c_cmd_handle_t cmd_handle = i2c_cmd_link_create();
    i2c_master_start(cmd_handle);
    i2c_master_write_byte(cmd_handle, (i2c_addr << 1) | I2C_MASTER_WRITE, true);
    i2c_master_write_byte(cmd_handle, reg_addr, true);
    i2c_master_start(cmd_handle);
    i2c_master_write_byte(cmd_handle, (i2c_addr << 1) | I2C_MASTER_READ, true);
    if (length > 1) {
        i2c_master_read(cmd_handle, reg_data, length - 1, I2C_MASTER_ACK);
    }
    i2c_master_read_byte(cmd_handle, reg_data + length - 1, I2C_MASTER_NACK);
    i2c_master_stop(cmd_handle);
    esp_err = i2c_master_cmd_begin(I2C_NUM_0, cmd_handle, 1000 / portTICK_PERIOD_MS);
 
    if (esp_err == ESP_OK) {
        iError = 0;
    } else {
        iError = -1;
    }
 
    i2c_cmd_link_delete(cmd_handle);
 
   
    return iError;
}

int8_t i2c_reg_write(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length) {
    /* Implement the I2C write routine according to the target machine. */
    int8_t iError;
    esp_err_t esp_err;
    i2c_cmd_handle_t cmd_handle = i2c_cmd_link_create();
    i2c_master_start(cmd_handle);
    i2c_master_write_byte(cmd_handle, (i2c_addr << 1) | I2C_MASTER_WRITE, true);
    i2c_master_write_byte(cmd_handle, reg_addr, true);
    i2c_master_write(cmd_handle, reg_data, length,true);
    i2c_master_stop(cmd_handle);
    esp_err = i2c_master_cmd_begin(I2C_NUM_0, cmd_handle, 1000 / portTICK_PERIOD_MS);
    if (esp_err == ESP_OK) {
        iError = 0;
    } else {
        iError = -1;
    }
    i2c_cmd_link_delete(cmd_handle);
    return iError;
}
 
/*!
 * Delay function map to  custom delay microsecond
 */
void _delay_us(uint32_t period) {
//ets_delay_us(period);       //add here custom delay for bmp280 library
}

/*!
 *  @brief Function to select the interface I2C.
 */
void i2cInit () {
ESP_LOGI(TAG_ADS1115,"I2C Interface\n");
ESP_LOGI(TAG_ADS1115,"Library version: %d\n",1);
i2c_master_init(); //initial i2c
}

/*!
 *  @brief Function deinitializes coines platform.
 */
void i2c_deinit(void) {
   //off/disable i2c
}