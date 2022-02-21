#include "Money.h"

vector<Exchange_Rate> init_exchange_rate_list();

int main() {
    exchange_rate_list = init_exchange_rate_list();

    Money m1{12.345, Currency::USD};
    cout << "m1: " << m1 << endl;

    Money m2{12.344, Currency::DKK};
    cout << "m2: " << m2 << endl;

    Money m3 = m1 + m2;
    cout << "m3: " << m3 << endl;

    keep_window_open();
    return 0;
}

vector<Exchange_Rate> init_exchange_rate_list() {
    vector<Exchange_Rate> rate_list;
    Exchange_Rate usd_to_dkk{Currency::USD, Currency::DKK, 6.5493};
    Exchange_Rate dkk_to_usd{Currency::DKK, Currency::USD, 0.1527};
    Exchange_Rate usd_to_cny{Currency::USD, Currency::CNY, 6.3231};
    Exchange_Rate cny_to_usd{Currency::CNY, Currency::USD, 0.1582};
    Exchange_Rate dkk_to_cny{Currency::DKK, Currency::CNY, 0.9654};
    Exchange_Rate cny_to_dkk{Currency::CNY, Currency::DKK, 1.0358};

    rate_list.push_back(usd_to_dkk);
    rate_list.push_back(dkk_to_usd);
    rate_list.push_back(usd_to_cny);
    rate_list.push_back(cny_to_usd);
    rate_list.push_back(dkk_to_cny);
    rate_list.push_back(cny_to_dkk);

    return rate_list;
}
