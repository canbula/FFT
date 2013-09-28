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
		ID_FIRST = wxID_HIGHEST + 1,
		ID_LAST
	};
	
	wxTextCtrl* inputvars;
	wxTextCtrl* outputvars;
	wxTextCtrl* outputformat;

	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

};
