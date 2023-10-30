#include "macos.hpp"

#include <cstring>
#include <mach-o/dyld.h>

namespace blehware::macos {
    std::uintptr_t get_base_address() {
        std::uintptr_t base_address = 0;

        char path[1024];
        std::uint32_t size = sizeof(path);

        _NSGetExecutablePath(path, &size);

        for (auto i = 0; i < _dyld_image_count(); i++) {
            if (strcmp(_dyld_get_image_name(i), path) == 0) {
                base_address = _dyld_get_image_vmaddr_slide(i);
                break;
            }
        }

        return base_address;
    }
}
