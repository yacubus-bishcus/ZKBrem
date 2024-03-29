#ifndef runAction_hh
#define runAction_hh 1

#include "G4UserRunAction.hh"
#include "G4Run.hh"

class runAction : public G4UserRunAction
{

public:
  runAction(G4bool);
  ~runAction();

  virtual void BeginOfRunAction(const G4Run*);
  virtual void EndOfRunAction(const G4Run*);

  void ReduceSlaveValuesToMaster();

private:
  G4bool sequentialArchitecture, parallelArchitecture;
  G4int nodeRank, totalEvents;
};


#endif
