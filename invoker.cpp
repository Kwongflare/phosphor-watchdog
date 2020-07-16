#include <cstdint>
#include <iostream>
#include <sdbusplus/bus.hpp>
#include <sdbusplus/message/append.hpp>

/** An example dbus client application.
 *   *  Calls org.freedesktop.login1's ListUsers interface to find all active
 *     *  users in the system and displays their username.
 *       */

int main()
{
    using namespace sdbusplus;

    printf("Controlla\n");
    auto b = bus::new_default_system();
    printf("Bus found\n");
    auto m =
        b.new_method_call("xyz.openbmc_project.Ipmi.Host", "/xyz/openbmc_project/Ipmi",
                "xyz.openbmc_project.Control.Server", "execute");
    printf("Method call created\n");

//    sdbusplus::message::append("xyz.openbmc_project.Control.Host", m, 1);

    auto reply = b.call(m);
    printf("Method called \n");

 //   std::cout << std::get<std::string>(reply) << "\n";

    return 0;

}

