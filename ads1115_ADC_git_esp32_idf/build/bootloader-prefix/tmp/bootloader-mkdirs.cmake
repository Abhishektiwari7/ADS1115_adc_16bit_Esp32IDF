# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/abhishek/esp-idf/components/bootloader/subproject"
  "/run/media/abhishek/Stark/Esp/Esp_IDF_Projects/ads1115_ADC_git_esp32_idf/build/bootloader"
  "/run/media/abhishek/Stark/Esp/Esp_IDF_Projects/ads1115_ADC_git_esp32_idf/build/bootloader-prefix"
  "/run/media/abhishek/Stark/Esp/Esp_IDF_Projects/ads1115_ADC_git_esp32_idf/build/bootloader-prefix/tmp"
  "/run/media/abhishek/Stark/Esp/Esp_IDF_Projects/ads1115_ADC_git_esp32_idf/build/bootloader-prefix/src/bootloader-stamp"
  "/run/media/abhishek/Stark/Esp/Esp_IDF_Projects/ads1115_ADC_git_esp32_idf/build/bootloader-prefix/src"
  "/run/media/abhishek/Stark/Esp/Esp_IDF_Projects/ads1115_ADC_git_esp32_idf/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/run/media/abhishek/Stark/Esp/Esp_IDF_Projects/ads1115_ADC_git_esp32_idf/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/run/media/abhishek/Stark/Esp/Esp_IDF_Projects/ads1115_ADC_git_esp32_idf/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
