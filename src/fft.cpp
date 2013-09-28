/*
    This file is part of FFT.

    FFT is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FFT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FFT.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "fft.h"

FFT::FFT(const wxString& title)
	: wxFrame(NULL,wxID_ANY,title,wxDefaultPosition,wxSize(640,480))
{
	
	wxFont fixedfont(11, wxMODERN, wxNORMAL, wxNORMAL);

	//wxImage::AddHandler(new wxPNGHandler);
	//wxBitmap toolbarLibrary(srcLocation+wxT("resource/toolbar/add.png"),wxBITMAP_TYPE_PNG);
	
	wxMenuBar *menubar = new wxMenuBar;
	wxMenu *file = new wxMenu;
	file->Append(ID_MENU_OPENINPUT,wxT("Open input file\tCtrl+O"));
	file->Append(ID_MENU_SAVEOUTPUT,wxT("Save output file\tCtrl+S"));
	file->AppendSeparator();
	file->Append(wxID_ABOUT,wxT("About\tCtrl+H"));
	file->Append(wxID_EXIT,wxT("Close"));
	menubar->Append(file,wxT("File"));
	SetMenuBar(menubar);
	
	wxStatusBar *statusbar = new wxStatusBar(this,wxID_ANY,wxST_SIZEGRIP);
	this->SetStatusBar(statusbar);
	statusbar->SetStatusText(wxT("FFT: Fortran Format Tool - Bora CANBULA - 2013"));
	
	wxPanel *outerpanel = new wxPanel(this,-1);
	wxBoxSizer *outerbox = new wxBoxSizer(wxHORIZONTAL);
	
	outerbox->Add(new wxStaticText(outerpanel,-1,wxT(" ")),0,wxEXPAND);

	wxPanel *mainpanel = new wxPanel(outerpanel,-1);
	wxBoxSizer *mainvbox = new wxBoxSizer(wxVERTICAL);
	
	mainvbox->Add(-1,5);
	
	wxPanel *top1panel = new wxPanel(mainpanel,-1);
	wxBoxSizer *top1box = new wxBoxSizer(wxHORIZONTAL);
	top1box->Add(new wxStaticText(top1panel,-1,wxT("Variables in input "),wxPoint(-1,-1),wxSize(180,-1)),0,wxEXPAND);
	inputvars = new wxTextCtrl(top1panel,-1,wxT(""));
	top1box->Add(inputvars,1,wxALIGN_RIGHT);
	top1panel->SetSizer(top1box);
	mainvbox->Add(top1panel,0,wxALIGN_LEFT|wxEXPAND);
	
	mainvbox->Add(-1,5);
	
	wxPanel *top2panel = new wxPanel(mainpanel,-1);
	wxBoxSizer *top2box = new wxBoxSizer(wxHORIZONTAL);
	top2box->Add(new wxStaticText(top2panel,-1,wxT("Variables in output "),wxPoint(-1,-1),wxSize(180,-1)),0,wxEXPAND);
	outputvars = new wxTextCtrl(top2panel,-1,wxT(""));
	top2box->Add(outputvars,1,wxALIGN_RIGHT);
	top2panel->SetSizer(top2box);
	mainvbox->Add(top2panel,0,wxALIGN_LEFT|wxEXPAND);
	
	mainvbox->Add(-1,5);
	
	wxPanel *top3panel = new wxPanel(mainpanel,-1);
	wxBoxSizer *top3box = new wxBoxSizer(wxHORIZONTAL);
	top3box->Add(new wxStaticText(top3panel,-1,wxT("Format of output "),wxPoint(-1,-1),wxSize(180,-1)),0,wxEXPAND);
	outputformat = new wxTextCtrl(top3panel,-1,wxT(""));
	top3box->Add(outputformat,1,wxALIGN_RIGHT);
	top3panel->SetSizer(top3box);
	mainvbox->Add(top3panel,0,wxALIGN_LEFT|wxEXPAND);
	
	mainvbox->Add(-1,5);
	
	wxPanel *middlepanel = new wxPanel(mainpanel,-1);
	wxBoxSizer *middlehbox = new wxBoxSizer(wxHORIZONTAL);

	wxPanel *leftpanel = new wxPanel(middlepanel,-1);
	wxBoxSizer *leftvbox = new wxBoxSizer(wxVERTICAL);
	inputtc = new wxTextCtrl(leftpanel,-1,wxT(""),wxPoint(-1,-1),wxSize(-1,-1),wxTE_MULTILINE);
	inputtc->SetFont(fixedfont);
	inputtc->SetValue(wxT(""));
	leftvbox->Add(inputtc,1,wxALIGN_CENTER|wxEXPAND);
	leftpanel->SetSizer(leftvbox);
	middlehbox->Add(leftpanel,1,wxALIGN_LEFT|wxEXPAND);

	wxStaticLine *middlehboxSEP = new wxStaticLine(middlepanel,-1,wxPoint(-1,-1),wxSize(-1,-1),wxLI_VERTICAL);
	middlehbox->Add(middlehboxSEP,0,wxEXPAND);

	wxPanel *rightpanel = new wxPanel(middlepanel,-1);
	wxBoxSizer *rightvbox = new wxBoxSizer(wxVERTICAL);
	outputtc = new wxTextCtrl(rightpanel,-1,wxT(""),wxPoint(-1,-1),wxSize(-1,-1),wxTE_MULTILINE);
	outputtc->SetFont(fixedfont);
	outputtc->SetValue(wxT(""));
	rightvbox->Add(outputtc,1,wxALIGN_CENTER|wxEXPAND);
	rightpanel->SetSizer(rightvbox);
	middlehbox->Add(rightpanel,1,wxALIGN_RIGHT|wxEXPAND);

	middlepanel->SetSizer(middlehbox);
	
	mainvbox->Add(middlepanel,1,wxEXPAND);
	
	mainpanel->SetSizer(mainvbox);
	
	outerbox->Add(mainpanel,1,wxALIGN_CENTER|wxEXPAND);
	
	outerbox->Add(new wxStaticText(outerpanel,-1,wxT(" ")),0,wxEXPAND);
	outerpanel->SetSizer(outerbox);
	
	Connect(wxID_ABOUT,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(FFT::OnAbout));
	Connect(wxID_EXIT,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(FFT::OnQuit));
	Connect(ID_MENU_OPENINPUT,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(FFT::OpenFileForInputMenu));
	Connect(ID_MENU_SAVEOUTPUT,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(FFT::SaveOutputAsFileMenu));
	
	SetIcon(wxIcon(wxT("resource/fft.xpm")));
	Centre();
	
}

void FFT::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxAboutDialogInfo info;
	info.SetName(wxT("FFT"));
	info.SetVersion(wxT("0.1"));
	info.SetDescription(wxT("Fortran Format Tool."));
	info.SetCopyright(wxT("Bora CANBULA <bc.jabba@gmail.com> (C) 2013"));
	wxAboutBox(info);
}

void FFT::OnQuit(wxCommandEvent& WXUNUSED(event)) {Close(true);}

void FFT::OpenFileForInputMenu(wxCommandEvent& event) {FFT::OpenFileForInput();}

void FFT::OpenFileForInput()
{
	wxFileDialog *newfileforinput = new wxFileDialog(this,wxT("Pick a text file for input.."));
	if(newfileforinput->ShowModal() == wxID_OK)
	{
		inputtc->LoadFile(newfileforinput->GetPath());
	}
}

void FFT::SaveOutputAsFileMenu(wxCommandEvent& event) {FFT::SaveOutputAsFile();}

void FFT::SaveOutputAsFile()
{
	wxFileDialog *filesaveas = new wxFileDialog(this,wxT("Save the output as text file.."),wxT(""),wxT("fft.out"),wxT("*.*"),wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if(filesaveas->ShowModal() == wxID_OK)
	{
		outputtc->SaveFile(filesaveas->GetPath());
	}
}
