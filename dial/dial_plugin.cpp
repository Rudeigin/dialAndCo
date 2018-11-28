#include "dial_plugin.h"
#include "focore.h"

#include <qqml.h>

void DialPlugin::registerTypes(const char *uri)
{
    // @uri ru.fo.dial
    qmlRegisterType<FOCore>(uri, 1, 0, "FOCore");
}

