#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDate>
#include <QString>

class Options
{
public:
    Options();
    void save_to_sql();

    void set_sql_id(unsigned int val) {b_sql_id = val;}
    void set_number_short(unsigned int val) {b_number_short = val;}
    void set_ticker(const QString& val) {b_ticker = val;}
    void set_premium(float val) {b_premium = val;}
    void set_expiry(const QDate& val) {b_expiry = val;}

    void mark_modified() {b_modified = true;}

private:
    unsigned int b_sql_id;
    unsigned int b_number_short;
    QString      b_ticker;
    float        b_premium;
    QDate        b_expiry;

    // need to flush to disk?
    bool         b_modified;
};

#endif // OPTIONS_H
