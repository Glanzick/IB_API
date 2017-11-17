#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDate>
#include <QString>

class Options
{
public:
    Options();
    void save_to_sql();

    void set_sql_id(const int val) {b_sql_id = val;}
    void set_number_short(const int val) {b_number_short = val;}
    void set_ticker(const QString& val) {b_ticker = val;}
    void set_premium(const float val) {b_premium = val;}
    void set_expiry(const QDate& val) {b_expiry = val;}
    void set_expired(const bool val) {b_expired = val;}

    void mark_modified() {b_modified = true;}

    static QString table_definition()
    {return QString("CREATE TABLE options ") +
                    "(id INTEGER PRIMARY KEY," +
                    " num INT," +
                    " ticker VARCHAR(20)," +
                    " premium FLOAT," +
                    " expiry VARCHAR(50)," +
                    " expired INT)";}

private:
    int     b_sql_id;
    int     b_number_short;
    QString b_ticker;
    float   b_premium;
    QDate   b_expiry;
    bool    b_expired;

    // need to flush to disk?
    bool    b_modified;
};

#endif // OPTIONS_H
