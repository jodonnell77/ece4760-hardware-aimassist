if (TARGET tinyusb_device)
    add_executable(hello_usb
            main.c
            )


    pico_enable_stdio_usb(hello_usb 1)
    pico_enable_stdio_uart(hello_usb 0)

    # must match with executable name and source file names

    target_sources(hello_usb PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/main.c
        ${CMAKE_CURRENT_LIST_DIR}/usb_descriptors.c
        )

    target_include_directories(hello_usb PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

    # must match with executable name
    target_link_libraries(hello_usb PRIVATE pico_stdlib tinyusb_device tinyusb_board tinyusb_host)

    # must match with executable name
    pico_add_extra_outputs(hello_usb)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()
