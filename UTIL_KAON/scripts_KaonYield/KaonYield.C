#define KaonYield_cxx
// The class definition in KaonYield.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("KaonYield.C")
// root> T->Process("KaonYield.C","some options")
// root> T->Process("KaonYield.C+")
//


#include "KaonYield.h"
#include <TStyle.h>
#include <TCanvas.h>
#include <TLine.h>

void KaonYield::Begin(TTree * /*tree*/)
{
  // The Begin() function is called at the start of the query.
  // When running with PROOF Begin() is only called on the client.
  // The tree argument is deprecated (on PROOF 0 is passed).

  TString option = GetOption();

  Info("Begin", "Starting Good Kaon Selection");
}

void KaonYield::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).

  TString option = GetOption();

  h2ROC1_Coin_Beta_noID = new TH2F("ROC1_Coin_Beta_noID","Coincident Time vs #beta for ROC1 (no particle ID);Time (ns);#beta",800,-40,40,200,0.0,2.0);
  h2ROC1_Coin_Beta = new TH2F("ROC1_Coin_Beta","Coincident Time vs #beta for ROC1;Time (ns);#beta",800,-40,40,200,0.0,2.0);

  h1HMS_electron        = new TH1F("HMS_electron","Normalized HMS Calorimeter Energy;Normalized Energy;Counts",200,0.01,2.0);
  h1HMS_electron_cut    = new TH1F("HMS_electron_cut","Normalized HMS Calorimeter Energy, Electrons Selected;Normalized Energy;Counts",200,0.01,2.0);

  h1SHMS_electron        = new TH1F("SHMS_electron","Normalized SHMS Calorimeter Energy;Normalized Energy;Counts",200,0.01,2.0);
  h1SHMS_electron_cut    = new TH1F("SHMS_electron_cut","Normalized SHM Calorimeter Energy, Electrons Removed;Normalized Energy;Counts",200,0.01,2.0);

  h2SHMS_kaon            = new TH2F("SHMS_kaon","NPE in SHMS Aerogel and Heavy Gas;Aerogel NPE;HGC NPE",50,0.1,25,50,0.1,10);
  h2SHMS_kaon_cut        = new TH2F("SHMS_kaon_cut","NPE in SHMS Aerogel and Heavy Gas, Kaons Selected;Aerogel NPE;HGC NPE",50,0.0,25,50,0.0,10);

  h1SHMS_delta           = new TH1F("SHMS_delta","SHMS #delta;#delta;Counts",100,-50,50);
  h1SHMS_delta_cut       = new TH1F("SHMS_delta_cut","SHMS #delta Cut;#delta;Counts",100,-50,50);
  h1HMS_delta            = new TH1F("HMS_delta","HMS #delta;#delta;Counts",100,-50,50);
  h1HMS_delta_cut        = new TH1F("HMS_delta_cut","HMS #delta Cut;#delta;Counts",100,-50,50);

  h1mmiss                = new TH1F("mmiss","Missing mass;Mass (GeV/c^{2});Counts",200,0,20.0);
  h1mmiss_cut            = new TH1F("mmiss_cut","Missing mass with Cuts;Mass (GeV/c^{2});Counts",200,0,3.0);

  GetOutputList()->Add(h2ROC1_Coin_Beta_noID);
  GetOutputList()->Add(h2ROC1_Coin_Beta);
  GetOutputList()->Add(h1HMS_electron);
  GetOutputList()->Add(h1HMS_electron_cut);
  GetOutputList()->Add(h1SHMS_electron);
  GetOutputList()->Add(h1SHMS_electron_cut);
  GetOutputList()->Add(h2SHMS_kaon);
  GetOutputList()->Add(h2SHMS_kaon_cut);
  GetOutputList()->Add(h1SHMS_delta);
  GetOutputList()->Add(h1SHMS_delta_cut);
  GetOutputList()->Add(h1HMS_delta);
  GetOutputList()->Add(h1HMS_delta_cut);
  GetOutputList()->Add(h1mmiss);
  GetOutputList()->Add(h1mmiss_cut);

}

Bool_t KaonYield::Process(Long64_t entry)
{
  // The Process() function is called for each entry in the tree (or possibly
  // keyed object in the case of PROOF) to be processed. The entry argument
  // specifies which entry in the currently loaded tree is to be processed.
  // When processing keyed objects with PROOF, the object is already loaded
  // and is available via the fObject pointer.
  //
  // This function should contain the \"body\" of the analysis. It can contain
  // simple or elaborate selection criteria, run algorithms on the data
  // of the event and typically fill histograms.
  //
  // The processing can be stopped by calling Abort().
  //
  // Use fStatus to set the return value of TTree::Process().
  //
  // The return value is currently not used.

  fReader.SetEntry(entry);

  //if (*fEvtType != 4) return kTRUE;

  
  
  h1HMS_electron->Fill(H_cal_etotnorm[0]);
  h1SHMS_electron->Fill(P_cal_etotnorm[0]);
  h2SHMS_kaon->Fill(P_aero_npeSum[0],P_hgcer_npeSum[0]);
  
  h1SHMS_delta->Fill(P_gtr_dp[0]);
  h1HMS_delta->Fill(H_gtr_dp[0]);

  h1mmiss->Fill(sqrt(pow(pmiss[0],2)+pow(emiss[0],2)));

  if (H_cal_etotnorm[0] < 0.9) return kTRUE;
  if (P_cal_etotnorm[0] > 0.6) return kTRUE;
  if (P_aero_npeSum[0] < 1.5 || P_hgcer_npeSum[0] > 1.5) return kTRUE;

  h2ROC1_Coin_Beta_noID->Fill((CTime_eKCoinTime_ROC1[0] - 10.0),P_gtr_beta[0]);

  if (TMath::Abs(H_gtr_dp[0]) > 10.0) return kTRUE;
  if (P_gtr_dp[0] > 10.0 || P_gtr_dp[0] < -22.0) return kTRUE;
  if (abs((CTime_eKCoinTime_ROC1[0] - 10.0)) > 1.0) return kTRUE;
  if (abs(P_gtr_beta[0]-1.00) > 0.1) return kTRUE;
  

  h2ROC1_Coin_Beta->Fill((CTime_eKCoinTime_ROC1[0] - 10.0),P_gtr_beta[0]);
  
  h1HMS_electron_cut->Fill(H_cal_etotnorm[0]);
  h1SHMS_electron_cut->Fill(P_cal_etotnorm[0]);
  h2SHMS_kaon_cut->Fill(P_aero_npeSum[0],P_hgcer_npeSum[0]);

  h1SHMS_delta_cut->Fill(P_gtr_dp[0]);
  h1HMS_delta_cut->Fill(H_gtr_dp[0]);

  h1mmiss_cut->Fill(sqrt(pow(pmiss[0],2)+pow(emiss[0],2)));

  return kTRUE;
}

void KaonYield::SlaveTerminate()
{
  // The SlaveTerminate() function is called after all entries or objects
  // have been processed. When running with PROOF SlaveTerminate() is called
  // on each slave server.

}

void KaonYield::Terminate()
{
  // The Terminate() function is the last function to be called during
  // a query. It always runs on the client, it can be used to present
  // the results graphically or save the results to file.

  Info("Terminate", "Outputting Good Kaon Selection");

  TCanvas *cID = new TCanvas("ID","Summary of Particle ID Cuts");
  cID->Divide(2,3);
  cID->cd(1); h1HMS_electron->Draw();
  cID->cd(2); h1HMS_electron_cut->Draw();
  cID->cd(3); h1SHMS_electron->Draw();
  cID->cd(4); h1SHMS_electron_cut->Draw();
  cID->cd(5); h2SHMS_kaon->Draw("Colz");
  cID->cd(6); h2SHMS_kaon_cut->Draw("Colz");

  TCanvas *cKine = new TCanvas("Kine","Summary of Kinetic Cuts");
  cKine->Divide(2,3);
  cKine->cd(1); h1HMS_delta->Draw();
  cKine->cd(2); h1HMS_delta_cut->Draw();
  cKine->cd(3); h1SHMS_delta->Draw();
  cKine->cd(4); h1SHMS_delta_cut->Draw();
  cKine->cd(5); h2ROC1_Coin_Beta_noID->Draw("Colz");
  TLine *TimeLower = new TLine(-1,0,-1,2.0);      TimeLower->SetLineColor(kRed); TimeLower->Draw();
  TLine *TimeUpper = new TLine(1,0,1,2.0);        TimeUpper->SetLineColor(kRed); TimeUpper->Draw();
  TLine *BetaLower = new TLine(-40,0.9,40,0.9); BetaLower->SetLineColor(kRed); BetaLower->Draw();
  TLine *BetaUpper = new TLine(-40,1.1,40,1.1); BetaUpper->SetLineColor(kRed); BetaUpper->Draw();
  cKine->cd(6); h2ROC1_Coin_Beta->Draw("Colz");

  TCanvas *cMiss = new TCanvas("Miss","Summary of Missing Mass");
  cMiss->Divide(2,1);
  cMiss->cd(1); h1mmiss->Draw();
  cMiss->cd(2); h1mmiss_cut->Draw();
  TF1 *Lambda_Fit = new TF1("Lambda_Fit","[1]*exp((-0.5)*(pow((x - [0]),2)/pow(([2]),2)))",0.75,1.5);
  Lambda_Fit->FixParameter(0,1.1156);
  Lambda_Fit->SetParameter(1,100);
  Lambda_Fit->SetParameter(2,0.11);
  Lambda_Fit->SetParName(0,"#mu");
  Lambda_Fit->SetParName(1,"Amplitude");
  Lambda_Fit->SetParName(2,"#sigma");
  h1mmiss_cut->Fit("Lambda_Fit","RMQ");
			    

  cout << Form("Number of good kaon events: %.0f +/- %.0f\n",Lambda_Fit->Integral(0.75,1.5),sqrt(Lambda_Fit->Integral(0.75,1.5)));

  // values for controlling format
  const string sep = "	" ;
  const int total_width = 154;
  const string line = sep + string( total_width-1, '-' ) + '|' ;


  ofstream myfile1;
  myfile1.open ("kaonyieldVar", fstream::app);
  myfile1 <<
    left << h1mmiss_cut->GetEntries() << "\n";
  myfile1.close();
}
