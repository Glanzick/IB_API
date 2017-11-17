#ifndef POSITIONS_H
#define POSITIONS_H

#include <vector>
#include <QSqlDatabase>
#include "options.h"

class Positions
{
public:
    Positions();
    void clear() {b_options.clear();}

    void load_positions_from_sql();
    void save_positions_to_sql();

    size_t num_options() const {return b_options.size();}
    void add_option(Options&& opt);

private:
    void load_options_from_sql();

private:
    std::vector<Options> b_options;
};

#endif // POSITIONS_H
