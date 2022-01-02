void kstar_decay_4_2() {
  // Carica i dati salvati da file
  TFile* histograms = new TFile("../histograms/kstar-decay-hist.root","READ");

  // Importa i grafici necessari per [4.2]
  TH1F* InvMassOppCharge    = (TH1F*)histograms->Get("InvMassOppCharge");   // (1)
  TH1F* InvMassSameCharge   = (TH1F*)histograms->Get("InvMassSameCharge");  // (2)
  TH1F* InvMassPKOppCharge  = (TH1F*)histograms->Get("InvMassPKOppCharge"); // (3)
  TH1F* InvMassPKSameCharge = (TH1F*)histograms->Get("InvMassPKSameCharge");// (4)
  TH1F* InvMassPKCouple     = (TH1F*)histograms->Get("InvMassPKCouple");    // (5)
    
  // Imposta lo stile
  gStyle->SetOptFit(1111);
  gStyle->SetOptStat("neM");

  // Crea una canvas per visualizzare i grafici e la divide in 4
  TCanvas* cv = new TCanvas("cv2", "", 1200, 800);
  cv->Divide(2, 2);

  // Crea l'istogramma di controllo
  InvMassPKCouple->Fit("gaus", "Q0");
  InvMassPKCouple->SetFillColor(7);
  InvMassPKCouple->SetTitle("Grafico B.5. Masse invarianti calcolate tra coppie P/K generate dai decadimenti (istogramma di controllo);Massa invariante(GeV/c^2);Numero occorrenze");

  // Crea l'istogramma differenza tra massa invariante di tutte le
  // particelle di segno opposto e concorde
  TH1F* InvMassSubtract = new TH1F(*InvMassSameCharge);
  InvMassSubtract->SetDrawOption("HIST");
  InvMassSubtract->SetTitle("Grafico B.6. Differenza tra masse invarianti di tutte le coppie di particelle di segno opposto e concorde;Massa invariante(GeV/c^2);Numero occorrenze");
  InvMassSubtract->Add(InvMassOppCharge, InvMassSameCharge, 1, -1); // (1) - (2)
  InvMassSubtract->Fit("gaus", "QB0");
  InvMassSubtract->SetFillColor(7);
  InvMassSubtract->SetAxisRange(0.4, 1.4);
  
  // Crea l'istogramma differenza tra massa invariante di tutte le
  // coppie P/K di segno opposto e concorde
  TH1F* InvMassPKSubtract = new TH1F(*InvMassPKSameCharge);
  InvMassPKSubtract->SetTitle("Grafico B.7. Differenza tra masse invarianti di tutte le coppie Pione/Kaone di segno opposto e concorde;Massa invariante(GeV/c^2);Numero occorrenze");
  InvMassPKSubtract->Add(InvMassPKOppCharge, InvMassPKSameCharge, 1, -1); // (3) - (4)
  InvMassPKSubtract->Fit("gaus", "QB0");
  InvMassPKSubtract->SetFillColor(7);
  InvMassPKSubtract->SetAxisRange(0.4, 1.4);
    
  cv->cd(1);
  InvMassPKCouple->Draw("HIST");
  TF1* ControlFit = InvMassPKCouple->GetFunction("gaus");
  ControlFit->Draw("same");
    
  cv->cd(2);
  InvMassSubtract->Draw("HIST");
  TF1* SubFit = InvMassSubtract->GetFunction("gaus");
  SubFit->Draw("same");
    
  cv->cd(3);
  InvMassPKSubtract->Draw("HIST");
  TF1* PKSubFit = InvMassPKSubtract->GetFunction("gaus");
  PKSubFit->Draw("same");
  
  cv->Draw();
}