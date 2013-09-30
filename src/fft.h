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

#include "wxlibs.h"

class FFT : public wxFrame
{
public:
	FFT(const wxString& title);
	
	enum
	{
		ID_MENU_OPENINPUT = wxID_HIGHEST + 1,
		ID_MENU_SAVEOUTPUT,
		ID_MENU_HANDLEINPUT,
		ID_MENU_RUN
	};
	
	wxArrayString* variablenames;
	wxArrayString* numbers;
	wxTextCtrl* inputvars;
	wxTextCtrl* outputvars;
	wxTextCtrl* inputformat;
	wxTextCtrl* outputformat;
	wxTextCtrl* inputtc;
	wxTextCtrl* outputtc;

	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OpenFileForInputMenu(wxCommandEvent& event);
	void OpenFileForInput();
	void SaveOutputAsFileMenu(wxCommandEvent& event);
	void SaveOutputAsFile();
	void HandleInputMenu(wxCommandEvent& event);
	void HandleInput();
	void RunMenu(wxCommandEvent& event);
	void Run();

};
