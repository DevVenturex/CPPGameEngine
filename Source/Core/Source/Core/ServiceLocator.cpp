#include "ServiceLocator.h"

#include <algorithm>

namespace Core
{
    void ServiceLocator::Update()
    {
        std::for_each(m_Services.cbegin(), m_Services.cend(), [](const std::unique_ptr<Service>& service)
            {
                service->OnUpdate();
            }
        );
    }

    template <typename S>
    requires(std::is_base_of_v<Service, S>)
    void ServiceLocator::AddService()
    {
        m_Services.push_back(std::make_unique<S>());
    }

    template <typename S>
    requires(std::is_base_of_v<Service, S>)
    S* ServiceLocator::GetService()
    {
        for (auto& service : m_Services)
        {
            if (auto result = dynamic_cast<S*>(service.get()))
            {
                return result;
            }
        }
        return nullptr;
    }
}