#include "commands.hpp"
#include "messages.hpp"
#include "payload.hpp"

// (void)data does nothing special, it is just used to avoid compiler warnings about a variable that is not used 

// Command functions array definition 
std::array<CommandFunction, COMMAND_NUMBER> COMMAND_FUNCTIONS = 
{
    neutral_ack,
    request_state,
    shutdown,
    synchronize_time,
    run_self_diagnostics,
    request_last_telemetry,
    set_telemetry_frequency,
    turn_on_cameras,
    turn_off_cameras,
    enable_camera_x,
    disable_camera_x,
    start_capture_images_every_x_seconds,
    stop_capture_images,
    stored_images,
    request_last_image,
    img_transfer_complete_ack,
    delete_all_stored_images,
    enable_region_x,
    disable_region_x,
    run_od,
    debug_display_camera
};

// Define the array of strings mapping CommandID to command names
std::array<std::string_view, COMMAND_NUMBER> COMMAND_NAMES = {
    "NEUTRAL_ACK",
    "REQUEST_STATE",
    "SHUTDOWN",
    "SYNCHRONIZE_TIME",
    "RUN_SELF_DIAGNOSTICS",
    "REQUEST_LAST_TELEMETRY",
    "SET_TELEMETRY_FREQUENCY",
    "TURN_ON_CAMERAS",
    "TURN_OFF_CAMERAS",
    "ENABLE_CAMERA_X",
    "DISABLE_CAMERA_X",
    "START_CAPTURE_IMAGES_EVERY_X_SECONDS",
    "STOP_CAPTURE_IMAGES",
    "STORED_IMAGES",
    "REQUEST_LAST_IMAGE",
    "IMG_TRANSFER_COMPLETE_ACK",
    "DELETE_ALL_STORED_IMAGES",
    "ENABLE_REGION_X",
    "DISABLE_REGION_X",
    "RUN_OD",
    "DEBUG_DISPLAY_CAMERA"
};

void neutral_ack(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Received Neutral Acknowledgement");
    // Do nothing
    (void)payload;
    (void)data;
    // TODO
}

void request_state(Payload& payload, std::vector<uint8_t>& data)
{
    payload.GetState();
    SPDLOG_INFO("State is: {} ", ToString(payload.GetState()));

    auto msg = std::make_shared<MSG_RequestState>();
    msg->state = static_cast<uint8_t>(payload.GetState());
    msg->serialize();

    payload.TransmitMessage(msg);

    (void)data;
}

void shutdown(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Initiating Payload shutdown..");
    payload.Stop();
    (void)data; // TODO
}

void synchronize_time(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Synchronizing time..");
    (void)payload;
    (void)data;
    // TODO
}

void run_self_diagnostics(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Running self diagnostics..");
    (void)payload;
    (void)data;
    // TODO
}

void request_last_telemetry(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Requesting last telemetry..");
    (void)payload;
    (void)data;
    // TODO
}

void set_telemetry_frequency(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Setting telemetry frequency..");
    (void)payload;
    (void)data;
    // TODO
}

void turn_on_cameras(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Turning on cameras..");

    payload.GetCameraManager().TurnOn();

    (void)data;
    // TODO
}

void turn_off_cameras(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Turning off cameras..");

    payload.GetCameraManager().TurnOff();

    (void)data;

}

void enable_camera_x(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Enabling camera X..");
    (void)payload;
    (void)data;
    // TODO
}

void disable_camera_x(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Disabling camera X..");
    (void)payload;
    (void)data;
    // TODO
}

void start_capture_images_every_x_seconds(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Starting capture images every X seconds..");
    (void)payload;
    (void)data;
    // TODO
}

void stop_capture_images(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Stopping capture images..");
    (void)payload;
    (void)data;
    // TODO
}
void stored_images(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Getting stored images..");
    (void)payload;
    (void)data;
    // TODO
}

void request_last_image(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Requesting last image..");
    (void)payload;
    (void)data;
    // TODO
}

void img_transfer_complete_ack(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Received Image Transfer Complete Acknowledgement");
    (void)payload;
    (void)data;
    // TODO
}

void delete_all_stored_images(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Deleting all stored images..");
    (void)payload;
    (void)data;
    // TODO
}

void enable_region_x(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Enabling region X..");
    (void)payload;
    (void)data;
    // TODO
}

void disable_region_x(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Disabling region X..");
    (void)payload;
    (void)data;
    // TODO
}

void run_od(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Running orbit determination..");
    (void)payload;
    (void)data;
    // TODO
}


void debug_display_camera(Payload& payload, std::vector<uint8_t>& data)
{
    SPDLOG_INFO("Activating the display of the camera");
    payload.GetCameraManager().DisplayLoop(true);
    (void)data; // TODO
}