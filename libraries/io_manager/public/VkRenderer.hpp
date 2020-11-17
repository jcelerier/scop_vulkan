#ifndef SCOP_VULKAN_VKRENDERER_HPP
#define SCOP_VULKAN_VKRENDERER_HPP

#include <array>
#include <vector>

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

class VkRenderer final
{
  public:
    VkRenderer() = default;
    ~VkRenderer() = default;
    VkRenderer(VkRenderer const &src) = delete;
    VkRenderer &operator=(VkRenderer const &rhs) = delete;
    VkRenderer(VkRenderer &&src) = delete;
    VkRenderer &operator=(VkRenderer &&rhs) = delete;

    void init(char const *app_name,
              char const *engine_name,
              uint32_t app_version,
              uint32_t engine_version);
    void clear();

  private:
    VkInstance _instance;
    VkDebugUtilsMessengerEXT _debug_messenger;

    inline void _create_instance(char const *app_name,
                                 char const *engine_name,
                                 uint32_t app_version,
                                 uint32_t engine_version);

    // Validation layers related
#ifdef NDEBUG
    static constexpr bool const ENABLE_VALIDATION_LAYER = false;
#else
    static constexpr bool const ENABLE_VALIDATION_LAYER = true;
#endif
    static constexpr std::array const VALIDATION_LAYERS{
        "VK_LAYER_KHRONOS_validation",
    };
    static inline bool _check_validation_layer_support();
    inline void _setup_vk_debug_msg();

    // Extension related
    static inline std::vector<char const *> _get_required_extensions();
};

#endif // SCOP_VULKAN_VKRENDERER_HPP