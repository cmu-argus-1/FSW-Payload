#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <mutex>
#include <atomic>
#include "frame.hpp"
#include <opencv2/opencv.hpp>
#include "configuration.hpp"

// 4608×2592
#define DEFAULT_CAMERA_WIDTH 640 // 4608
#define DEFAULT_CAMERA_HEIGHT 480 // 2592
#define DEFAULT_CAMERA_FPS 30 // 10

#define MAX_CONSECUTIVE_ERROR_COUNT 3 // before disabling 

enum class CAM_STATUS : uint8_t {
    UNDEFINED = 0,
    DISABLED = 1,
    TURNED_ON = 2,
    TURNED_OFF = 3
};

enum class CAM_ERROR : uint8_t {
    NO_ERROR = 0x00,
    CAPTURE_FAILED = 0x01,
    INITIALIZATION_FAILED = 0x02
};

class Camera
{


public:
    Camera(int id, std::string path, bool enabled = false);
    Camera(const CameraConfig& config);

    // Attempt to enable the camera. Returns true if successful
    bool Enable();
    // Disable the camera. Returns true if successful
    bool Disable();
    bool IsEnabled() const;

    void TurnOn();
    void TurnOff();
    // void Restart(); // Restart after failure, but need to avoid loops

    bool CaptureFrame();
    const Frame& GetBufferFrame() const;


    int GetCamId() const;
    CAM_STATUS GetCamStatus() const;


    void DisplayLastFrame();

    void LoadIntrinsics(const cv::Mat& intrinsics, const cv::Mat& distortion_parameters);


private:

    std::atomic<CAM_STATUS> cam_status;
    CAM_ERROR last_error;
    
    
    int cam_id;
    std::string cam_path;
    cv::VideoCapture cap;


    Frame buffer_frame;

    int width = DEFAULT_CAMERA_WIDTH;
    int height = DEFAULT_CAMERA_HEIGHT;

    cv::Mat intrinsics;
    cv::Mat distortion_parameters; 



    int consecutive_error_count = 0;
    void HandleErrors(CAM_ERROR error);

};










#endif // CAMERA_HPP