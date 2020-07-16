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
        b.new_method_call("org.freedesktop.DBus", "/org/freedesktop/DBus",
                "org.freedesktop.DBus", "ListNames");
    printf("Method call created\n");

//    sdbusplus::message::append("xyz.openbmc_project.Control.Host", m, 1);

    auto reply = b.call(m);
    printf("Method called \n");
    
    printf("%s", reply[0]);

    return 0;

}

