#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp

#include <string>
using namespace std;

class EuropeanOption {
  private:
    void init();
    void copy(const EuropeanOption& o2);
    double CallPrice() const;
    double PutPrice() const;
    double CallDelta() const;
    double PutDelta() const;

    double n(double x) const;
    double N(double x) const;
  public:
    double r;
    double sig;
    double K;
    double T;
    double U;
    double b;
    string optType;
  public:
    EuropeanOption();
    EuropeanOption(const EuropeanOption& option2);
    EuropeanOption(const string& optionType);

    virtual ~EuropeanOption();

    EuropeanOption& operator=(const EuropeanOption& option2);

    double Price() const;
    double Delta() const;

    void toggle();
};
#endif
