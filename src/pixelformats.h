#ifndef PIXELFORMATS_H_
#define PIXELFORMATS_H_

#include <VmbC/VmbCommonTypes.h>

// Helper as GStreamer only provides these macros for x-raw formats
#define GST_BAYER_FORMATS_ALL "{ bggr, grbg, gbrg, rggb }"

#define GST_BAYER_CAPS_MAKE(format)       \
    "video/x-bayer, "                     \
    "format = (string) " format ", "      \
    "width = " GST_VIDEO_SIZE_RANGE ", "  \
    "height = " GST_VIDEO_SIZE_RANGE ", " \
    "framerate = " GST_VIDEO_FPS_RANGE

typedef struct
{
    const char *vimbax_format_name;
    const char *gst_format_name;
} VimbaXGstFormatMatch_t;

// TODO: Check if same capitalization as below for the VimbaX capabilities is guaranteed
static VimbaXGstFormatMatch_t vimbax_gst_format_matches[] = {
    {"Mono8", "GRAY8"},
    {"Mono10", "GRAY16_LE"},
    {"Mono12", "GRAY16_LE"},
    {"Mono14", "GRAY16_LE"},
    {"Mono16", "GRAY16_LE"},
    {"RGB8", "RGB"},
    {"RGB8Packed", "RGB"},
    {"BGR8", "BGR"},
    {"BGR8Packed", "BGR"},
    {"Argb8", "ARGB"},
    {"Rgba8", "RGBA"},
    {"Bgra8", "BGRA"},
    {"Yuv411", "IYU1"},
    {"YUV411Packed", "IYU1"},
    {"YCbCr411_8_CbYYCrYY", "IYU1"},
    {"Yuv422", "UYVY"},
    {"YUV422Packed", "UYVY"},
    {"YCbCr422_8_CbYCrY", "UYVY"},
    {"Yuv444", "IYU2"},
    {"YUV444Packed", "IYU2"},
    {"YCbCr8_CbYCr", "IYU2"},
    {"BayerGR8", "grbg"},
    {"BayerRG8", "rggb"},
    {"BayerGB8", "gbrg"},
    {"BayerBG8", "bggr"}};
#define NUM_FORMAT_MATCHES (sizeof(vimbax_gst_format_matches) / sizeof(vimbax_gst_format_matches[0]))

// lookup supported gst cap by format string from camera
const VimbaXGstFormatMatch_t *gst_format_from_vimbax_format(const char *vimbax_format);

// lookup camera format string by negotiated gst cap
const VimbaXGstFormatMatch_t *vimbax_format_from_gst_format(const char *gst_format);

#endif // PIXELFORMATS_H_