#ifndef UNIT_COMMITMENT_H
#define UNIT_COMMITMENT_H
#include "generator.h"
#include "economic_dispatch.h"

class Unit_Commitment {

private:
  Generator overallGenArray[];
  Generator optimizedGenArray[];
  int predictedLoad;
  int timeCycle;
  Economic_Dispatch ecoDis;

public:
  Unit_Commitment(Generator genArray[], int pLoad, int tc);

  Generator * getOptimizedArray();
  int getEconomicDispatch();
}
#endif //UNIT_COMMITMENT_H
