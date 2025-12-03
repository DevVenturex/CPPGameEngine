#pragma once

namespace Core
{
    class Service
    {
    public:
        Service() = default;
        virtual ~Service() = default;

        virtual void OnUpdate() = 0;
    };
}