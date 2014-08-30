#include "State.h"
#include "Exception.h"
#include "LibBase.h"
#include "LibIO.h"
#include "LibMath.h"
#include "LibString.h"
#include "LibTable.h"
#include <stdio.h>

int main(int argc, const char **argv)
{
    if (argc < 2)
    {
        printf("usage: %s file\n", argv[0]);
        return 0;
    }

    try
    {
        luna::State state;

        lib::base::RegisterLibBase(&state);
        lib::io::RegisterLibIO(&state);
        lib::math::RegisterLibMath(&state);
        lib::string::RegisterLibString(&state);
        lib::table::RegisterLibTable(&state);

        state.DoModule(argv[1]);
    }
    catch (const luna::OpenFileFail &exp)
    {
        printf("%s: can not open file %s\n", argv[0], exp.What().c_str());
    }
    catch (const luna::Exception &exp)
    {
        printf("%s\n", exp.What().c_str());
    }

    return 0;
}