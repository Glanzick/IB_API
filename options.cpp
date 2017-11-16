#include "options.h"

Options::Options()
    : b_modified(false)
{

}

void Options::save_to_sql()
{
    if (! b_modified) return;

    b_modified = false;
}
