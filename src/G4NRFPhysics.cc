// C++ source file to encapsulate the G4NRF physics process
// Jayson Vavrek, MIT, 2016
// jvavrek@mit.edu

#include "G4NRFPhysics.hh"

#include "G4RayleighScattering.hh"
#include "G4LivermoreRayleighModel.hh"

G4NRFPhysics::G4NRFPhysics(const G4String &name) : G4VPhysicsConstructor("NRF")
{
	//G4cout << "In G4NRFPhysics() constructor" << G4endl;

	G4LossTableManager::Instance();
	SetPhysicsType(0);
}

G4NRFPhysics::~G4NRFPhysics()
{}

void G4NRFPhysics::ConstructParticle()
{}

void G4NRFPhysics::ConstructProcess()
{
	//G4cout << "In G4NRFPhysics::ConstructProcess()" << G4endl;

	G4NRF *nrf = new G4NRF("NRF");
	
  // Check if Geant4 version is >= 10.3.0
  #if G4MAJV * 10000 + G4MINV * 100 + G4SUBV > 100299
	auto aParticleIterator=GetParticleIterator();
  #endif

	aParticleIterator->reset();
  while( (*aParticleIterator)() ) {
    G4ParticleDefinition       *particle = aParticleIterator->value();
    G4ProcessManager *particleProcessMgr = particle->GetProcessManager();
    G4String                particleName = particle->GetParticleName();
		/*
    G4cout << " G4NRFPhysics: particle = "           << particle << G4endl;
    G4cout << " G4NRFPhysics: particleProcessMgr = " << particleProcessMgr << G4endl;
    G4cout << " G4NRFPhysics: particleName = "       << particleName << G4endl;
    G4cout << G4endl;
		*/
    if (particleName == "gamma"){
    	particleProcessMgr->AddDiscreteProcess(nrf);

    	// custom-add Rayleigh. Might not work well alongside standard EM
      //G4RayleighScattering* rayl = new G4RayleighScattering("Rayl");
      //G4LivermoreRayleighModel* raylModel = new G4LivermoreRayleighModel();
      //raylModel->SetHighEnergyLimit(1.0*GeV);
      //rayl->AddEmModel(0, raylModel);
      //particleProcessMgr->AddDiscreteProcess(rayl);
    }
  }

}
