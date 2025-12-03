#pragma once

#include "Service.h"
#include "WindowService.h"

#include <vector>
#include <memory>

namespace Core
{
    class ServiceLocator
    {
    public:
        ServiceLocator() = default;
        ~ServiceLocator() = default;

        void Update();

        template<typename S>
        requires(std::is_base_of_v<Service, S>)
        void AddService();

        template <typename S>
        requires(std::is_base_of_v<Service, S>)
        S* GetService();

    private:
        std::vector<std::unique_ptr<Service>> m_Services;
    };
}