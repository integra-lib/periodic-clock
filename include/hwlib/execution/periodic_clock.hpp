#pragma once

#include <chrono>
#include <functional>

namespace hwlib::execution
{

/// Time and tick source abstraction. Isolates the only two real-hardware
/// dependencies of an adapter layer — a monotonic clock and a periodic tick —
/// so the code above it stays host-testable with a fake implementation.
class IPeriodicClock
{
public:
    virtual ~IPeriodicClock() = default;

    // Current monotonic time since boot.
    [[nodiscard]] virtual std::chrono::milliseconds NowMs() const = 0;

    // Arms a periodic tick that invokes onTick every interval. onTick may run
    // from a different execution context (e.g. an interrupt) than the caller —
    // implementations must document their own callback context.
    virtual void StartTick(std::chrono::milliseconds interval, std::function<void()> onTick) = 0;

    virtual void StopTick() = 0;
};

} // namespace hwlib::execution
