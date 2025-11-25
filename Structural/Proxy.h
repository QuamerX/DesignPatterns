#pragma once

struct IService
{
    virtual void performAction() = 0;
    virtual ~IService() = default;
};

struct RealService : IService
{
    void performAction() override
    {
        std::cout << "Action performed!\n";
    }
};

struct ServiceProxy : IService
{
    std::unique_ptr<RealService> real;
    bool hasAccess;

    ServiceProxy(bool access) : hasAccess(access) {}

    void performAction() override
    {
        if (!hasAccess)
        {
            std::cout << "Access denied.\n";
            return;
        }
        if (!real)
            real = std::make_unique<RealService>();
        real->performAction();
    }
};
