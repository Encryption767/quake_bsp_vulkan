#pragma once

#include "renderer/vulkan/Base.hpp"
#include "renderer/vulkan/Device.hpp"

namespace vk
{
    struct Texture
    {
        VkImage image = VK_NULL_HANDLE;
        VmaAllocation allocation = VK_NULL_HANDLE;
        VkImageView imageView = VK_NULL_HANDLE;
        VkSampler sampler = VK_NULL_HANDLE;
        VkFormat format = VK_FORMAT_UNDEFINED;
        VkFilter minFilter = VK_FILTER_LINEAR;
        VkFilter magFilter = VK_FILTER_LINEAR;
    }; // todo: add format?

    void createTextureImage(const Device &device, const VkCommandPool &commandPool, Texture *dstTex, const unsigned char *pixels, uint32_t imageWidth, uint32_t imageHeight, int imageComponents);
    VkResult createImageView(const Device &device, const VkImage &image, VkImageAspectFlags aspectFlags, VkImageView *imageView, VkFormat format);
    VkResult createTextureImageView(const Device &device, Texture *texture);
    VkResult createTextureSampler(const Device &device, Texture *texture);
    void createTexture(const Device &device, const VkCommandPool &commandPool, Texture *dstTex, const unsigned char *data, uint32_t width, uint32_t height, int components);
    void releaseTexture(const Device &device, Texture *texture);
    Texture createDepthResources(const Device &device, const SwapChain &swapChain, const VkCommandPool &commandPool);
}
