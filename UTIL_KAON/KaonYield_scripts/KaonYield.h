//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jul  6 10:04:53 2018 by ROOT version 6.10/02
// from TTree T/Hall A Analyzer Output DST
// found on file: /home/rambrose/hallc_replay/ROOTfiles/coin_replay_production_4270_-1.root
//////////////////////////////////////////////////////////

#ifndef KaonYield_h
#define KaonYield_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include <TH2.h>


// Headers needed by this particular selector


class KaonYield : public TSelector {
 public :
  TTreeReader     fReader;  //!the tree reader
  TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

  //Declare Histograms
  TH2F           *h2ROC1_Coin_Beta_noID;
  TH2F           *h2ROC1_Coin_Beta;

  TH1F           *h1HMS_electron;
  TH1F           *h1HMS_electron_cut;
  TH1F           *h1SHMS_electron;
  TH1F           *h1SHMS_electron_cut;

  TH2F           *h2SHMS_kaon;
  TH2F           *h2SHMS_kaon_cut;

  TH1F           *h1SHMS_delta;
  TH1F           *h1SHMS_delta_cut;
  TH1F           *h1HMS_delta;
  TH1F           *h1HMS_delta_cut;

  TH1F           *h1mmiss;
  TH1F           *h1mmiss_cut;

  // Readers to access the data (delete the ones you do not need).
  TTreeReaderArray<Double_t> CTime_eKCoinTime_ROC1 = {fReader, "CTime.eKCoinTime_ROC1"};
  TTreeReaderArray<Double_t> P_gtr_beta         = {fReader, "P.gtr.beta"};
  TTreeReaderArray<Double_t> H_gtr_beta         = {fReader, "H.gtr.beta"};
  TTreeReaderArray<Double_t> H_cal_etotnorm     = {fReader, "H.cal.etotnorm"}; 
  TTreeReaderArray<Double_t> P_cal_etotnorm     = {fReader, "P.cal.etotnorm"};
  TTreeReaderArray<Double_t> P_aero_npeSum      = {fReader, "P.aero.npeSum"};
  TTreeReaderArray<Double_t> P_hgcer_npeSum     = {fReader, "P.hgcer.npeSum"};
  TTreeReaderArray<Double_t> H_gtr_dp           = {fReader, "H.gtr.dp"};
  TTreeReaderArray<Double_t> P_gtr_dp           = {fReader, "P.gtr.dp"};
  TTreeReaderArray<Double_t> emiss              = {fReader, "P.kin.secondary.emiss"};
  TTreeReaderArray<Double_t> pmiss              = {fReader, "P.kin.secondary.pmiss"};
  TTreeReaderValue<Int_t>    fEvtType           = {fReader, "fEvtHdr.fEvtType"};


  KaonYield(TTree * /*tree*/ =0) {h2ROC1_Coin_Beta_noID=0, h2ROC1_Coin_Beta=0, h1HMS_electron=0, h1HMS_electron_cut=0, h1SHMS_electron=0, h1SHMS_electron_cut=0, h2SHMS_kaon=0, h2SHMS_kaon_cut=0, h1SHMS_delta=0, h1SHMS_delta_cut=0, h1HMS_delta=0, h1HMS_delta_cut=0, h1mmiss=0, h1mmiss_cut=0;}
  virtual ~KaonYield() { }
  virtual Int_t   Version() const { return 2; }
  virtual void    Begin(TTree *tree);
  virtual void    SlaveBegin(TTree *tree);
  virtual void    Init(TTree *tree);
  virtual Bool_t  Notify();
  virtual Bool_t  Process(Long64_t entry);
  virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
  virtual void    SetOption(const char *option) { fOption = option; }
  virtual void    SetObject(TObject *obj) { fObject = obj; }
  virtual void    SetInputList(TList *input) { fInput = input; }
  virtual TList  *GetOutputList() const { return fOutput; }
  virtual void    SlaveTerminate();
  virtual void    Terminate();

  ClassDef(KaonYield,0);

};

#endif

#ifdef KaonYield_cxx
void KaonYield::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the reader is initialized.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  fReader.SetTree(tree);
}

Bool_t KaonYield::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}


#endif // #ifdef KaonYield_cxx
