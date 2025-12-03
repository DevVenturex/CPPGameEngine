#include <Core/ServiceLocator.h>
#include <Core/WindowService.h>

int main(void)
{
    Core::ServiceLocator locater{};
    locater.AddService<Core::WindowService>();

    Core::WindowService* windowService = locater.GetService<Core::WindowService>();
    while (!windowService->ShouldPrimaryWindowClose())
    {
        locater.Update();

        windowService = locater.GetService<Core::WindowService>();
    }
    return 0;
}