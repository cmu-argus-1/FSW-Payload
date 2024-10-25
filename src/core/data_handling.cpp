#include "core/data_handling.hpp"


bool make_directory(std::string_view directory_path)
{
    bool success = false;
    if (std::filesystem::exists(directory_path)) {
        SPDLOG_INFO("Folder already exists.");
        success = true;
    } else if (std::filesystem::create_directory(directory_path)) {
        SPDLOG_INFO("Data folder created.");
        success = true;
    } else {
        SPDLOG_CRITICAL("Failed to create data folder.");
    }    

    return success;

}


long GetFileSize(std::string_view file_path) 
{
    struct stat stat_buf;
    int rc = stat(std::string(file_path).c_str(), &stat_buf);
    return rc == 0LL ? stat_buf.st_size : -1LL;
}


long GetDirectorySize(std::string_view directory_path) 
{
    long total_size = 0;
    struct stat stat_buf;
    for (const auto& entry : std::filesystem::recursive_directory_iterator(directory_path)) {
        if (entry.is_regular_file()) {
            if (stat(entry.path().c_str(), &stat_buf) == 0) {
                total_size += stat_buf.st_size;
            }
        }
    }
    return total_size;
}


DataHandler::DataHandler()
: init_data_folder_tree(false)
{
}


bool DataHandler::InitializeDataStorage()
{
    if (init_data_folder_tree) {
        SPDLOG_INFO("Data folder tree already initialized.");
        return true;
    }

    // Construct the full paths using the root and subdirectory names
    std::vector<std::string> directories = {
        f_root,
        f_images,
        f_telemetry,
        f_experiments,
        f_logging
    };

    bool success = true;
    for (const auto& dir : directories) {
        if (!make_directory(dir)) {
            SPDLOG_CRITICAL("Failed to create directory: {}", dir);
            success = false;
        }
    }

    init_data_folder_tree = success;

    if (success) {
        SPDLOG_INFO("Data folder tree initialized successfully.");
    }

    return success;
}
