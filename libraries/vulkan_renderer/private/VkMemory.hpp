#ifndef SCOP_VULKAN_VKMEMORY_HPP
#define SCOP_VULKAN_VKMEMORY_HPP

#include <cstdint>
#include <vulkan/vulkan.h>

uint32_t findMemoryType(VkPhysicalDevice physical_device,
                        uint32_t type_filter,
                        VkMemoryPropertyFlags properties);
void createBuffer(VkPhysicalDevice physicalDevice,
                  VkDevice device,
                  VkDeviceSize size,
                  VkBufferUsageFlags usage,
                  VkMemoryPropertyFlags properties,
                  VkBuffer &buffer,
                  VkDeviceMemory &buffer_memory);

#endif // SCOP_VULKAN_VKMEMORY_HPP