#include "bindto.h"

//(*InternalHeaders(Bindto)
#include <wx/string.h>
#include <wx/intl.h>
//*)

#include <editormanager.h>
#include <cbstyledtextctrl.h>
#include <configmanager.h>
#include <projectmanager.h>
#include <logmanager.h>
#include <cbproject.h>
#include <wx/regex.h>
#include <wx/tokenzr.h>
#include <wx/textdlg.h>
#include <wx/dirdlg.h>

//(*IdInit(Bindto)
const long Bindto::ID_BTOACTIVEPROJECT = wxNewId();
const long Bindto::ID_BTOCURRENTFILE = wxNewId();
const long Bindto::ID_TEXTCTRL1 = wxNewId();
const long Bindto::ID_STATICTEXT5 = wxNewId();
const long Bindto::ID_CHECKBOX3 = wxNewId();
const long Bindto::ID_TEXTCTRL6 = wxNewId();
const long Bindto::ID_STATICTEXT1 = wxNewId();
const long Bindto::ID_TEXTCTRL7 = wxNewId();
const long Bindto::ID_BUTTON1 = wxNewId();
const long Bindto::ID_PANEL2 = wxNewId();
const long Bindto::ID_LV_TYPES = wxNewId();
const long Bindto::ID_BUTTON_ADD = wxNewId();
const long Bindto::ID_BUTTON_COPY = wxNewId();
const long Bindto::ID_BUTTON_EDIT = wxNewId();
const long Bindto::ID_BUTTON_REMOVE = wxNewId();
const long Bindto::ID_BUTTON_DEFAULTS = wxNewId();
const long Bindto::ID_PANEL1 = wxNewId();
const long Bindto::ID_CHECKBOX4 = wxNewId();
const long Bindto::ID_TEXTCTRL4 = wxNewId();
const long Bindto::ID_CHECKBOX5 = wxNewId();
const long Bindto::ID_TEXTCTRL5 = wxNewId();
const long Bindto::ID_PANEL3 = wxNewId();
const long Bindto::ID_CHECKBOX1 = wxNewId();
const long Bindto::ID_TEXTCTRL2 = wxNewId();
const long Bindto::ID_CHECKBOX2 = wxNewId();
const long Bindto::ID_TEXTCTRL3 = wxNewId();
const long Bindto::ID_PANEL4 = wxNewId();
const long Bindto::ID_CHECKBOX6 = wxNewId();
const long Bindto::ID_TEXTCTRL8 = wxNewId();
const long Bindto::ID_CHECKBOX7 = wxNewId();
const long Bindto::ID_CHECKBOX8 = wxNewId();
const long Bindto::ID_PANEL6 = wxNewId();
const long Bindto::ID_PANEL5 = wxNewId();
const long Bindto::ID_NOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Bindto,wxDialog)
	//(*EventTable(Bindto)
	//*)
	EVT_BUTTON  (wxID_OK, Bindto::OnOK)
END_EVENT_TABLE()

wxString DIM_VAR_KEY = _T("<<@%%@>>");
wxString PROCNAME_KEY = _T("$procname$");
wxString MODULENAME_KEY = _T("$modulename$");
wxString MODNAME_KEY = _T("$modname$");

Bindto::Bindto(wxWindow* parent, ParserF* pParser)
{
	//(*Initialize(Bindto)
	wxBoxSizer* BoxSizer15;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxStaticText* StaticText13;
	wxStaticText* StaticText14;
	wxStaticText* StaticText15;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer16;
	wxBoxSizer* BoxSizer10;
	wxNotebook* nb_settings;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer11;
	wxBoxSizer* BoxSizer13;
	wxBoxSizer* BoxSizer2;
	wxStaticText* StaticText1;
	wxStaticText* StaticText10;
	wxBoxSizer* BoxSizer17;
	wxBoxSizer* BoxSizer9;
	wxBoxSizer* BoxSizer18;
	wxStaticText* StaticText3;
	wxBoxSizer* BoxSizer19;
	wxStaticText* StaticText12;
	wxBoxSizer* BoxSizer4;
	wxPanel* Panel3;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer20;
	wxStaticText* StaticText4;
	wxBoxSizer* BoxSizer1;
	wxStaticText* StaticText5;
	wxStaticText* StaticText2;
	wxBoxSizer* BoxSizer12;
	wxBoxSizer* BoxSizer14;
	wxStaticText* StaticText9;
	wxBoxSizer* BoxSizer6;
	wxStdDialogButtonSizer* StdDialogButtonSizer1;
	wxBoxSizer* BoxSizer5;

	Create(parent, wxID_ANY, _("Bind To"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	nb_settings = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
	Panel2 = new wxPanel(nb_settings, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	BoxSizer7 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(Panel2, wxID_ANY, _("This tool generates a wrapping for Fortran code to be called from the C language."), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	BoxSizer7->Add(StaticText1, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(Panel2, wxID_ANY, _("Generate wrapping for:"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	BoxSizer7->Add(StaticText2, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3->Add(30,0,0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	rb_ActiveProject = new wxRadioButton(Panel2, ID_BTOACTIVEPROJECT, _("Active project"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_BTOACTIVEPROJECT"));
	BoxSizer3->Add(rb_ActiveProject, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	rb_CurrentFile = new wxRadioButton(Panel2, ID_BTOCURRENTFILE, _("Current file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTOCURRENTFILE"));
	BoxSizer3->Add(rb_CurrentFile, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(BoxSizer3, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(Panel2, wxID_ANY, _("BIND(C, name=#):"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	BoxSizer8->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tc_bindCName = new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	tc_bindCName->SetToolTip(_("Write how the names called from C code will be constructed.\nVariables \"$procname$\", \"$modulename$\" and \"$modname$\" will be changed procedure, module and truncated module names corespondingly."));
	BoxSizer8->Add(tc_bindCName, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(BoxSizer8, 0, wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText16 = new wxStaticText(Panel2, ID_STATICTEXT5, _("Note: $procname$ is changed to the original name of procedure;\n         $modulename$ is changed to the name of module;\n         $modname$ is changed to the truncated name of module."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer7->Add(StaticText16, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer15 = new wxBoxSizer(wxVERTICAL);
	cb_globalToOne = new wxCheckBox(Panel2, ID_CHECKBOX3, _("Add wrapper code for global procedures into one file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	cb_globalToOne->SetValue(false);
	BoxSizer15->Add(cb_globalToOne, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer16 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer16->Add(30,0,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	st_globalFilename = new wxStaticText(Panel2, wxID_ANY, _("File name:"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	BoxSizer16->Add(st_globalFilename, 0, wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_globalFilename = new wxTextCtrl(Panel2, ID_TEXTCTRL6, _("myprocedures.f90"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	BoxSizer16->Add(tc_globalFilename, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer15->Add(BoxSizer16, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(BoxSizer15, 0, wxTOP|wxBOTTOM|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
	StaticText7 = new wxStaticText(Panel2, ID_STATICTEXT1, _("Output dir:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer17->Add(StaticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tc_OutputDir = new wxTextCtrl(Panel2, ID_TEXTCTRL7, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	BoxSizer17->Add(tc_OutputDir, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	bt_OutputDir = new wxButton(Panel2, ID_BUTTON1, _("..."), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer17->Add(bt_OutputDir, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(BoxSizer17, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Panel2->SetSizer(BoxSizer7);
	BoxSizer7->Fit(Panel2);
	BoxSizer7->SetSizeHints(Panel2);
	Panel1 = new wxPanel(nb_settings, ID_PANEL1, wxPoint(314,298), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	StaticText3 = new wxStaticText(Panel1, wxID_ANY, _("Binding types"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	BoxSizer4->Add(StaticText3, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	lv_Types = new wxListView(Panel1, ID_LV_TYPES, wxDefaultPosition, wxSize(500,300), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES|wxSUNKEN_BORDER, wxDefaultValidator, _T("ID_LV_TYPES"));
	BoxSizer4->Add(lv_Types, 1, wxTOP|wxBOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	bt_Add = new wxButton(Panel1, ID_BUTTON_ADD, _("Add"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_ADD"));
	bt_Add->SetToolTip(_("Add a new type"));
	BoxSizer5->Add(bt_Add, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	bt_copy = new wxButton(Panel1, ID_BUTTON_COPY, _("Copy"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_COPY"));
	bt_copy->SetToolTip(_("Copy selected type to a new one"));
	BoxSizer5->Add(bt_copy, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	bt_Edit = new wxButton(Panel1, ID_BUTTON_EDIT, _("Edit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_EDIT"));
	bt_Edit->SetToolTip(_("Edit selected type"));
	BoxSizer5->Add(bt_Edit, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	bt_Remove = new wxButton(Panel1, ID_BUTTON_REMOVE, _("Remove"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REMOVE"));
	bt_Remove->SetToolTip(_("Remove selected type"));
	BoxSizer5->Add(bt_Remove, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	bt_Defaults = new wxButton(Panel1, ID_BUTTON_DEFAULTS, _("Defaults"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_DEFAULTS"));
	bt_Defaults->SetToolTip(_("Restore default binding types"));
	BoxSizer5->Add(bt_Defaults, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(BoxSizer5, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxTOP|wxBOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	Panel3 = new wxPanel(nb_settings, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	BoxSizer10 = new wxBoxSizer(wxVERTICAL);
	StaticText4 = new wxStaticText(Panel3, wxID_ANY, _("Recognize procedure, which name starts/ends with # as a constructor:"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	BoxSizer10->Add(StaticText4, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer12->Add(30,0,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(2, 2, 2, 1);
	cb_ctorStart = new wxCheckBox(Panel3, ID_CHECKBOX4, _("Constructor starts with:"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
	cb_ctorStart->SetValue(false);
	FlexGridSizer2->Add(cb_ctorStart, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
	tc_ctorStart = new wxTextCtrl(Panel3, ID_TEXTCTRL4, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	FlexGridSizer2->Add(tc_ctorStart, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
	cb_ctorEnd = new wxCheckBox(Panel3, ID_CHECKBOX5, _("Constructor ends with:"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
	cb_ctorEnd->SetValue(false);
	FlexGridSizer2->Add(cb_ctorEnd, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
	tc_ctorEnd = new wxTextCtrl(Panel3, ID_TEXTCTRL5, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	FlexGridSizer2->Add(tc_ctorEnd, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer12->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer11->Add(BoxSizer12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer10->Add(BoxSizer11, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
	Panel3->SetSizer(BoxSizer10);
	BoxSizer10->Fit(Panel3);
	BoxSizer10->SetSizeHints(Panel3);
	Panel4 = new wxPanel(nb_settings, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
	BoxSizer9 = new wxBoxSizer(wxVERTICAL);
	StaticText9 = new wxStaticText(Panel4, wxID_ANY, _("Recognize subroutine, which name starts/ends with # as a destructor:"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	BoxSizer9->Add(StaticText9, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer14->Add(30,0,0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1 = new wxFlexGridSizer(2, 2, 2, 0);
	cb_dtorStart = new wxCheckBox(Panel4, ID_CHECKBOX1, _("Destructor starts with:"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	cb_dtorStart->SetValue(false);
	FlexGridSizer1->Add(cb_dtorStart, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
	tc_dtorStart = new wxTextCtrl(Panel4, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer1->Add(tc_dtorStart, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	cb_dtorEnd = new wxCheckBox(Panel4, ID_CHECKBOX2, _("Destructor ends with:"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	cb_dtorEnd->SetValue(false);
	FlexGridSizer1->Add(cb_dtorEnd, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
	tc_dtorEnd = new wxTextCtrl(Panel4, ID_TEXTCTRL3, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer1->Add(tc_dtorEnd, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer14->Add(FlexGridSizer1, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer13->Add(BoxSizer14, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer9->Add(BoxSizer13, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
	StaticText10 = new wxStaticText(Panel4, wxID_ANY, _("Note: a default destructor is created for the derived type if"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	BoxSizer9->Add(StaticText10, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText12 = new wxStaticText(Panel4, wxID_ANY, _("         another destructor is not found."), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	BoxSizer9->Add(StaticText12, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
	Panel4->SetSizer(BoxSizer9);
	BoxSizer9->Fit(Panel4);
	BoxSizer9->SetSizeHints(Panel4);
	Panel5 = new wxPanel(nb_settings, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
	BoxSizer18 = new wxBoxSizer(wxVERTICAL);
	StaticText13 = new wxStaticText(Panel5, wxID_ANY, _("This tool can generate Cython code which wraps Fortran. Generated *.pyx file\n can later be compiled into an extention module for the Python language."), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	BoxSizer18->Add(StaticText13, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cb_genCython = new wxCheckBox(Panel5, ID_CHECKBOX6, _("Generate Cython *.pyx file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
	cb_genCython->SetValue(false);
	BoxSizer18->Add(cb_genCython, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	pn_pyOpts = new wxPanel(Panel5, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
	BoxSizer20 = new wxBoxSizer(wxVERTICAL);
	BoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
	StaticText14 = new wxStaticText(pn_pyOpts, wxID_ANY, _("Python function names:"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	BoxSizer19->Add(StaticText14, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tc_pyFunName = new wxTextCtrl(pn_pyOpts, ID_TEXTCTRL8, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	BoxSizer19->Add(tc_pyFunName, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer20->Add(BoxSizer19, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText15 = new wxStaticText(pn_pyOpts, wxID_ANY, _("Note: $procname$ is changed to the original name of procedure;\n         $modulename$ is changed to the name of module;\n         $modname$ is changed to the truncated name of module."), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	BoxSizer20->Add(StaticText15, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cb_pyGenClass = new wxCheckBox(pn_pyOpts, ID_CHECKBOX7, _("Generate Python class from Fortran module"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX7"));
	cb_pyGenClass->SetValue(false);
	BoxSizer20->Add(cb_pyGenClass, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cb_pyFirstSelf = new wxCheckBox(pn_pyOpts, ID_CHECKBOX8, _("Use first argument of the derived type as \'self\' in Python"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX8"));
	cb_pyFirstSelf->SetValue(false);
	BoxSizer20->Add(cb_pyFirstSelf, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	pn_pyOpts->SetSizer(BoxSizer20);
	BoxSizer20->Fit(pn_pyOpts);
	BoxSizer20->SetSizeHints(pn_pyOpts);
	BoxSizer18->Add(pn_pyOpts, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel5->SetSizer(BoxSizer18);
	BoxSizer18->Fit(Panel5);
	BoxSizer18->SetSizeHints(Panel5);
	nb_settings->AddPage(Panel2, _("General"), false);
	nb_settings->AddPage(Panel1, _("Types"), false);
	nb_settings->AddPage(Panel3, _("Constructor"), false);
	nb_settings->AddPage(Panel4, _("Destructor"), false);
	nb_settings->AddPage(Panel5, _("Python"), false);
	BoxSizer6->Add(nb_settings, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer6, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StdDialogButtonSizer1 = new wxStdDialogButtonSizer();
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_OK, wxEmptyString));
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_CANCEL, wxEmptyString));
	StdDialogButtonSizer1->Realize();
	BoxSizer1->Add(StdDialogButtonSizer1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BTOACTIVEPROJECT,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&Bindto::Onrb_ActiveProjectSelect);
	Connect(ID_BTOCURRENTFILE,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&Bindto::Onrb_ActiveProjectSelect);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bindto::Onbt_OutputDirClick);
	Connect(ID_BUTTON_ADD,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bindto::OnAdd);
	Connect(ID_BUTTON_COPY,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bindto::OnCopy);
	Connect(ID_BUTTON_EDIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bindto::OnEdit);
	Connect(ID_BUTTON_REMOVE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bindto::OnRemove);
	Connect(ID_BUTTON_DEFAULTS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bindto::OnDefaults);
	Connect(ID_CHECKBOX4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&Bindto::OnClick_cbCtorStart);
	Connect(ID_CHECKBOX5,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&Bindto::OnClick_cbCtorEnd);
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&Bindto::OnClick_cbDtorStart);
	Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&Bindto::OnClick_cbDtorEnd);
	Connect(ID_CHECKBOX6,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&Bindto::Oncb_genCythonClick);
	//*)

    lv_Types->InsertColumn(0,_T("Fortran"));
    lv_Types->InsertColumn(1,_T("Fortran Bind(C)"));
    lv_Types->InsertColumn(2,_T("C"));

	rb_CurrentFile->SetValue(true);
    m_pParser = pParser;

    m_TabSize = -1;
    cbEditor* ed = Manager::Get()->GetEditorManager()->GetBuiltinActiveEditor();
    if (ed)
    {
        cbStyledTextCtrl* control = ed->GetControl();
        if (control)
            m_TabSize = control->GetTabWidth();
    }
    if (m_TabSize == -1)
        m_TabSize = 4;

    LoadInitialValues();
    FillTypeList();
    for (int i=0; i< lv_Types->GetColumnCount(); i++)
    {
        lv_Types->SetColumnWidth(i,wxLIST_AUTOSIZE);
        if (lv_Types->GetColumnWidth(i) > 200)
            lv_Types->SetColumnWidth(i,200);
    }

    tc_bindCName->SetValue(m_BindCName);
    if (m_CtorStartsWith.IsEmpty())
    {
        cb_ctorStart->SetValue(false);
        tc_ctorStart->SetValue(_T("ctor_"));
        tc_ctorStart->Enable(false);
    }
    else
    {
        cb_ctorStart->SetValue(true);
        tc_ctorStart->SetValue(m_CtorStartsWith);
        tc_ctorStart->Enable(true);
    }

    cb_globalToOne->SetValue(m_OneGProcFile);
    tc_globalFilename->SetValue(m_OneGProcFileName);
    bool enab = false;
    if (rb_ActiveProject->GetValue())
        enab = true;
    cb_globalToOne->Enable(enab);
    tc_globalFilename->Enable(enab);
    st_globalFilename->Enable(enab);

    GetInitialOutputDir(m_InitialOutputDirFile, m_InitialOutputDirProj);
    if (rb_CurrentFile->GetValue())
        tc_OutputDir->SetValue(m_InitialOutputDirFile);
    else
        tc_OutputDir->SetValue(m_InitialOutputDirProj);

    if (m_CtorEndsWith.IsEmpty())
    {
        cb_ctorEnd->SetValue(false);
        tc_ctorEnd->SetValue(_T("_ctor"));
        tc_ctorEnd->Enable(false);
    }
    else
    {
        cb_ctorEnd->SetValue(true);
        tc_ctorEnd->SetValue(m_CtorEndsWith);
        tc_ctorEnd->Enable(true);
    }

    if (m_DtorStartsWith.IsEmpty())
    {
        cb_dtorStart->SetValue(false);
        tc_dtorStart->SetValue(_T("dtor_"));
        tc_dtorStart->Enable(false);
    }
    else
    {
        cb_dtorStart->SetValue(true);
        tc_dtorStart->SetValue(m_DtorStartsWith);
        tc_dtorStart->Enable(true);
    }

    if (m_DtorEndsWith.IsEmpty())
    {
        cb_dtorEnd->SetValue(false);
        tc_dtorEnd->SetValue(_T("_dtor"));
        tc_dtorEnd->Enable(false);
    }
    else
    {
        cb_dtorEnd->SetValue(true);
        tc_dtorEnd->SetValue(m_DtorEndsWith);
        tc_dtorEnd->Enable(true);
    }

    cb_genCython->SetValue(m_PyGenCython);
    pn_pyOpts->Enable(m_PyGenCython);
    tc_pyFunName->SetValue(m_PyFuncName);
    cb_pyGenClass->SetValue(m_PyCreateClass);
    cb_pyFirstSelf->SetValue(m_PyFirstArgAsSelf);

    FillC2NumpyTypesMap();
}

Bindto::~Bindto()
{
	//(*Destroy(Bindto)
	//*)
}
void Bindto::FillTypeList()
{
    if (!lv_Types)
        return;

    lv_Types->DeleteAllItems();
    int idx = 0;
    for ( TypeMap::iterator it=m_TypeMap.begin(); it != m_TypeMap.end(); ++it)
    {
        lv_Types->InsertItem(idx, it->first);
        lv_Types->SetItem(idx, 1, it->second[0]);
        lv_Types->SetItem(idx, 2, it->second[1]);
        idx++;
    }
}

void Bindto::FillC2NumpyTypesMap()
{
    m_C2NumpyTypes[_T("int")] = _T("intc");
    m_C2NumpyTypes[_T("float")] = _T("float32");
    m_C2NumpyTypes[_T("double")] = _T("float64");
}

void Bindto::LoadInitialValues()
{
    m_IsTypeMapDefault = false;
    LoadBindToConfig();

    if (m_TypeMap.size() == 0)
        FillTypeMapDefault();
}

void Bindto::FillTypeMapDefault()
{
    wxArrayString fTypes;
    wxArrayString bTypes;
    wxArrayString cTypes;
    fTypes.Add(_T("integer"));
    bTypes.Add(_T("integer(c_int)"));
    cTypes.Add(_T("int"));

    fTypes.Add(_T("integer(8)"));
    bTypes.Add(_T("integer(c_int64_t)"));
    cTypes.Add(_T("int64_t"));

    fTypes.Add(_T("integer(4)"));
    bTypes.Add(_T("integer(c_int32_t)"));
    cTypes.Add(_T("int32_t"));

    fTypes.Add(_T("integer(2)"));
    bTypes.Add(_T("integer(c_int16_t)"));
    cTypes.Add(_T("int16_t"));

    fTypes.Add(_T("integer(1)"));
    bTypes.Add(_T("integer(c_int8_t)"));
    cTypes.Add(_T("int8_t"));

    fTypes.Add(_T("integer(c_int)"));
    bTypes.Add(_T("integer(c_int)"));
    cTypes.Add(_T("int"));

    fTypes.Add(_T("real"));
    bTypes.Add(_T("real(c_float)"));
    cTypes.Add(_T("float"));

    fTypes.Add(_T("real(4)"));
    bTypes.Add(_T("real(c_float)"));
    cTypes.Add(_T("float"));

    fTypes.Add(_T("real(8)"));
    bTypes.Add(_T("real(c_double)"));
    cTypes.Add(_T("double"));

    fTypes.Add(_T("doubleprecision"));
    bTypes.Add(_T("real(c_double)"));
    cTypes.Add(_T("double"));

    fTypes.Add(_T("real(c_float)"));
    bTypes.Add(_T("real(c_float)"));
    cTypes.Add(_T("float"));

    fTypes.Add(_T("real(c_double)"));
    bTypes.Add(_T("real(c_double)"));
    cTypes.Add(_T("double"));

    fTypes.Add(_T("complex"));
    bTypes.Add(_T("complex(c_float_complex)"));
    cTypes.Add(_T("float complex"));

    fTypes.Add(_T("complex*8"));
    bTypes.Add(_T("complex(c_float_complex)"));
    cTypes.Add(_T("float complex"));

    fTypes.Add(_T("complex*16"));
    bTypes.Add(_T("complex(c_double_complex)"));
    cTypes.Add(_T("double complex"));

    fTypes.Add(_T("complex*32"));
    bTypes.Add(_T("complex(c_long_double_complex)"));
    cTypes.Add(_T("long double complex"));

    fTypes.Add(_T("complex(4)"));
    bTypes.Add(_T("complex(c_float_complex)"));
    cTypes.Add(_T("float complex"));

    //requires <complex.h>
    fTypes.Add(_T("complex(8)"));
    bTypes.Add(_T("complex(c_double_complex)"));
    cTypes.Add(_T("double complex"));

    //requires <complex.h>
    fTypes.Add(_T("complex(16)"));
    bTypes.Add(_T("complex(c_long_double_complex)"));
    cTypes.Add(_T("long double complex"));

    fTypes.Add(_T("logical"));
    bTypes.Add(_T("integer(c_int)"));
    cTypes.Add(_T("int"));

    fTypes.Add(_T("character"));
    bTypes.Add(_T("character(kind=c_char)"));
    cTypes.Add(_T("char"));

    fTypes.Add(_T("character(kind=c_char)"));
    bTypes.Add(_T("character(kind=c_char)"));
    cTypes.Add(_T("char"));

    m_TypeMap.clear();
    for (size_t i=0; i<fTypes.size(); i++)
    {
        wxArrayString ct;
        ct.Add(bTypes[i]);
        ct.Add(cTypes[i]);
        m_TypeMap[fTypes[i]] = ct;
    }
    m_IsTypeMapDefault = true;
}

void Bindto::LoadBindToConfig()
{
    m_IsTypeMapDefault = false;
    m_TypeMap.clear();
    ConfigManager* cfg = Manager::Get()->GetConfigManager(_T("fortran_project"));
    if (!cfg)
        return;

    wxArrayString list = cfg->EnumerateSubPaths(_T("/bind_to"));
    for (unsigned int i = 0; i < list.GetCount(); ++i)
    {
        if (!list[i].StartsWith(_T("type")))
            continue;
        wxString fT = cfg->Read(_T("/bind_to/") + list[i] + _T("/f_type"), wxEmptyString);
        wxString bT = cfg->Read(_T("/bind_to/") + list[i] + _T("/b_type"), wxEmptyString);
        wxString cT = cfg->Read(_T("/bind_to/") + list[i] + _T("/c_type"), wxEmptyString);

        if (fT.IsEmpty())
            continue;

        wxArrayString bct;
        bct.Add(bT);
        bct.Add(cT);
        m_TypeMap[fT] = bct;
    }

    m_OneGProcFile = cfg->ReadBool(_T("/bind_to/one_gproc_file"), true);
    m_OneGProcFileName = cfg->Read(_T("/bind_to/one_gproc_filename"), _T("procedures_bc.f90"));
    m_BindCName = cfg->Read(_T("/bind_to/bind_c_name"), PROCNAME_KEY);
    m_CtorStartsWith = cfg->Read(_T("/bind_to/ctor_start"), wxEmptyString);
    m_CtorEndsWith = cfg->Read(_T("/bind_to/ctor_end"), wxEmptyString);
    m_DtorStartsWith = cfg->Read(_T("/bind_to/dtor_start"), wxEmptyString);
    m_DtorEndsWith = cfg->Read(_T("/bind_to/dtor_end"), wxEmptyString);

    m_PyGenCython = cfg->ReadBool(_T("/bind_to/python_generate"), false);
    m_PyCreateClass = cfg->ReadBool(_T("/bind_to/python_class"), false);
    m_PyFirstArgAsSelf = cfg->ReadBool(_T("/bind_to/python_firstself"), true);
    m_PyFuncName = cfg->Read(_T("/bind_to/python_function_name"), PROCNAME_KEY+_T("_f"));
}

void Bindto::SaveBindToConfig()
{
    ConfigManager* cfg = Manager::Get()->GetConfigManager(_T("fortran_project"));
    if (!cfg)
        return;
    cfg->DeleteSubPath(_T("/bind_to"));

    if (!m_IsTypeMapDefault) // no need to save default types
    {
        TypeMap::iterator it;
        int count = 0;
        for (it = m_TypeMap.begin(); it != m_TypeMap.end(); ++it)
        {
            wxString fT = it->first;
            wxString bT = it->second[0];
            wxString cT = it->second[1];

            ++count;
            wxString key;
            key.Printf(_T("/bind_to/type%d/f_type"), count);
            cfg->Write(key, fT);
            key.Printf(_T("/bind_to/type%d/b_type"), count);
            cfg->Write(key, bT);
            key.Printf(_T("/bind_to/type%d/c_type"), count);
            cfg->Write(key, cT);
        }
    }

    cfg->Write(_T("/bind_to/one_gproc_file"), m_OneGProcFile);
    cfg->Write(_T("/bind_to/one_gproc_filename"), m_OneGProcFileName);
    cfg->Write(_T("/bind_to/bind_c_name"), m_BindCName);
    cfg->Write(_T("/bind_to/ctor_start"), m_CtorStartsWith);
    cfg->Write(_T("/bind_to/ctor_end"), m_CtorEndsWith);
    cfg->Write(_T("/bind_to/dtor_start"), m_DtorStartsWith);
    cfg->Write(_T("/bind_to/dtor_end"), m_DtorEndsWith);

    cfg->Write(_T("/bind_to/python_generate"), m_PyGenCython);
    cfg->Write(_T("/bind_to/python_class"), m_PyCreateClass);
    cfg->Write(_T("/bind_to/python_firstself"), m_PyFirstArgAsSelf);
    cfg->Write(_T("/bind_to/python_function_name"), m_PyFuncName);
}

void Bindto::OnOK(wxCommandEvent& event)
{
    BindToIn btin;
    if (rb_ActiveProject->GetValue())
        btin = bindToProject;
    else
        btin = bindToFile;

    m_BindCName = tc_bindCName->GetValue();
    m_BindCName.Replace(_T(" "), _T(""));
    if (m_BindCName.IsEmpty())
        m_BindCName = PROCNAME_KEY;

    m_OneGProcFile = cb_globalToOne->GetValue();
    m_OneGProcFileName = tc_globalFilename->GetValue();
    if (m_OneGProcFileName.Trim().Trim(false).IsEmpty())
    {
        m_OneGProcFileName = _T("procedures_bc.f90");
    }
    if (btin == bindToProject && m_OneGProcFile)
        m_UseOneGlobalFile = true;
    else
        m_UseOneGlobalFile = false;

    m_OutputDir = tc_OutputDir->GetValue().Trim(true).Trim(false);
    if(!MakeOutputDir())
    {
        wxString msg = _("Output directory cannot be created.\nCorrect \"Output dir\" text field.");
        cbMessageBox( msg, _("Error"), wxICON_ERROR);
        return;
    }

    if (cb_ctorStart->GetValue())
        m_CtorStartsWith = tc_ctorStart->GetValue();
    else
        m_CtorStartsWith = wxEmptyString;
    m_CtorStartsWith.Replace(_T(" "), _T(""));

    if (cb_ctorEnd->GetValue())
        m_CtorEndsWith = tc_ctorEnd->GetValue();
    else
        m_CtorEndsWith = wxEmptyString;
    m_CtorEndsWith.Replace(_T(" "), _T(""));

    if (cb_dtorStart->GetValue())
        m_DtorStartsWith = tc_dtorStart->GetValue();
    else
        m_DtorStartsWith = wxEmptyString;
    m_DtorStartsWith.Replace(_T(" "), _T(""));

    if (cb_dtorEnd->GetValue())
        m_DtorEndsWith = tc_dtorEnd->GetValue();
    else
        m_DtorEndsWith = wxEmptyString;
    m_DtorEndsWith.Replace(_T(" "), _T(""));

    m_PyGenCython = cb_genCython->GetValue();
    m_PyFuncName = tc_pyFunName->GetValue();
    m_PyFuncName.Replace(_T(" "),_T(""));
    if (m_PyGenCython && !VlidatePyFuncName())
        return;
    m_PyCreateClass = cb_pyGenClass->GetValue();
    m_PyFirstArgAsSelf = cb_pyFirstSelf->GetValue();

    SaveBindToConfig();
    MakeBindTo(btin);

    if (m_CreatedMsg.size() > 0)
    {
        size_t nmsg = std::min(m_CreatedMsg.size(),size_t(5));
        wxString msg;
        for (size_t i=0; i< nmsg; i++)
        {
            msg << m_CreatedMsg.Item(i) << _T("\n");
        }
        cbMessageBox( msg, _("Bindto Info"), wxICON_INFORMATION);
    }

    EndModal(wxID_OK);
}

void Bindto::MakeBindTo(BindToIn btin)
{
    if (!Manager::Get()->GetEditorManager() || !m_pParser)
        return;

    if (btin == bindToProject)
    {
        cbProject* project = Manager::Get()->GetProjectManager()->GetActiveProject();
        if (!project)
            return;

        m_GlobProceduresFile = _T("");
        m_GlobProceduresFileH = _T("");
        m_GlobProceduresCInclude.clear();
        m_GlobWriteIntToLog = false;
        m_GlobWriteLogToInt = false;
        m_GlobWriteStrCtoF = false;
        m_GlobWriteStrFtoC = false;
        m_GlobWriteStrLen = false;

        wxArrayString nonFFiles;
        wxArrayString projFiles;
        for (FilesList::iterator it = project->GetFilesList().begin(); it != project->GetFilesList().end(); ++it)
        {
            projFiles.Add((*it)->file.GetFullPath());
        }
        projFiles.Sort();
        for (size_t i=0; i<projFiles.size(); i++)
        {
            FortranSourceForm fsForm;
            if (g_FortranFileExt.IsFileFortran(projFiles.Item(i), fsForm))
                FileBindTo(projFiles.Item(i));
            else
                nonFFiles.Add(projFiles.Item(i));
        }

        if (m_UseOneGlobalFile && !m_GlobProceduresFile.IsEmpty())
        {
            wxFileName fname(m_OneGProcFileName);
            fname.SetPath(m_OutputDir);

            while (fname.FileExists())
            {
                wxString query_overwrite;
                query_overwrite << _("Warning:\n")
                  << _("This tool is about OVERWRITE the following existing file:\n")
                  << fname.GetFullPath()
                  << _("\n\nAre you sure that you want to OVERWRITE the file?");
                int answ = cbMessageBox(query_overwrite, _("Confirmation"),
                                 wxICON_WARNING | wxYES_NO | wxNO_DEFAULT);
                if (answ == wxID_NO)
                {
                    wxString name = fname.GetFullName();
                    wxString msg = _("Suggest a new file name:");

                    wxTextEntryDialog dlg(this, msg, _("File name"), name);
                    if (dlg.ShowModal() == wxID_OK)
                    {
                        name = dlg.GetValue().Trim(true).Trim(false);
                        if (!name.IsEmpty())
                            fname.SetFullName(name);
                    }
                }
                else if (answ == wxID_YES)
                    break;
                else
                {
                    wxString msg = _("Generation of the wrapping was canceled!");
                    cbMessageBox( msg, _("Bindto Info"), wxICON_INFORMATION);
                    return;
                }
            }
            wxString helperMod = GetHelperModule(true);
            wxString strGlobMod;
            m_Indent = 0;
            strGlobMod << _T("module ") << fname.GetName() << _T("_bc\n");
            m_Indent++;
            strGlobMod << GetIS() << _T("use, intrinsic :: iso_c_binding\n");
            if (!helperMod.IsEmpty())
                strGlobMod << GetIS() << _T("use :: bindc_helper_bc\n");
            strGlobMod << GetIS() << _T("implicit none\n");
            strGlobMod << _T("contains\n\n");

            wxString strGlobModEnd = _T("end module\n");

            wxFile f(fname.GetFullPath(), wxFile::write);
            cbWrite(f, m_GlobProcWarnMessages + SplitLines(helperMod,Fortran) + strGlobMod +
                    SplitLines(m_GlobProceduresFile,Fortran) + strGlobModEnd + GetEOLStr(), wxFONTENCODING_UTF8);

            if (!m_GlobProceduresFileH.IsEmpty())
            {
                wxFileName hfname(fname);
                hfname.SetExt(_T("h"));

                wxString hstr1;
                hstr1 << _T("#ifndef ") << hfname.GetName().Upper() << _T("_H") << _T("\n");
                hstr1 << _T("#define ") << hfname.GetName().Upper() << _T("_H") << _T("\n\n");
                StrSet::iterator it;
                for (it=m_GlobProceduresCInclude.begin(); it != m_GlobProceduresCInclude.end(); ++it)
                {
                    hstr1 << *it << _T("\n");
                }
                wxString hstr2 = _T("\n#endif");

                wxFile hf(hfname.GetFullPath(), wxFile::write);
                cbWrite(hf, hstr1 + _T("\n") + SplitLines(m_GlobProceduresFileH,C) + hstr2 + GetEOLStr(), wxFONTENCODING_UTF8);
            }

            if (!m_GlobProcWarnMessages.IsEmpty())
            {
                m_CreatedMsg.Add(_("\nThere were problems met during the generation of wrapping. A message was added to the beginning of ")
                                 +fname.GetFullName()+_(" file."));
            }
        }

        if (nonFFiles.size() > 0)
        {
            wxString mstr;
            if (nonFFiles.size() == 1)
            {
                mstr = _("File \"") + nonFFiles[0] + _("\" was not recognized as a Fortran file.");
                mstr << _(" The BindTo was not applied for it.");
            }
            else
            {
                mstr = _("Files");
                size_t i=0;
                size_t imax=5;
                while (i < nonFFiles.size() && i < imax)
                {
                    mstr << _("\n\"") << nonFFiles[i] << _T("\"");
                    i++;
                }
                if (nonFFiles.size() > imax)
                    mstr << _T("...\n");
                else
                    mstr << _T("\n");
                mstr << wxString::Format(_T("(%d "), nonFFiles.size()) << _("files) ");
                mstr << _("were not recognized as the Fortran files.");
                mstr << _(" The BindTo was not applied for them.");
                cbMessageBox(mstr, _("Info"), wxICON_INFORMATION);
            }
        }
    }
    else
    {
        // Bind current file
        cbEditor* ed = Manager::Get()->GetEditorManager()->GetBuiltinActiveEditor();
        if (!ed)
            return;
        FileBindTo(ed->GetFilename());
    }
}

void Bindto::FileBindTo(const wxString& filename)
{
    FortranSourceForm fsForm;
    if (!g_FortranFileExt.IsFileFortran(filename, fsForm))
    {
        cbMessageBox( _("The file \n") + filename +
                      _("\n is not recognized as a Fortran Source File."), _("Info"),
                      wxICON_INFORMATION);
        return;
    }
    TokenF* fileToken = m_pParser->FindFile(filename);

    if (!fileToken)
        return;

    m_CInclude.clear();
    m_CStructs = _T("");
    m_WarnMessage = _T("");
    wxString txtBindGM;
    wxString txtBindMod;
    wxString txtHeadersGM;
    wxString txtHeadersMod;
    bool inModuleGM = false;
    m_WriteStrCtoF = false;
    m_WriteStrFtoC = false;
    m_WriteStrLen = false;
    m_WriteIntToLog = false;
    m_WriteLogToInt = false;
    m_Indent   = 0;
    m_PyIndent = 0;
    wxFileName fn(fileToken->m_Filename);
    wxString globModName = fn.GetName() + _T("_proc_bc");
    m_CurFile = fn.GetFullName();
    m_InFortranModule = false;

    wxString txtCythonFirst;
    wxString txtCythonGP;
    wxString txtCythonMod;
    m_PyInclude.clear();

    TokensArrayF* fchen = &fileToken->m_Children;
    for (size_t i=0; i<fchen->GetCount(); i++)
    {
        if (fchen->Item(i)->m_TokenKind == tkSubroutine ||
            fchen->Item(i)->m_TokenKind == tkFunction)
        {
            if (!inModuleGM && !m_UseOneGlobalFile)
            {
                txtBindGM << _T("module ") << globModName << _T("\n");
                m_Indent++;
                txtBindGM << GetIS() << _T("use, intrinsic :: iso_c_binding\n");
                txtBindGM << _T("$#$#%^@@place for helper module$#@%");
                txtBindGM << GetIS() << _T("implicit none\n");
                txtBindGM << _T("contains\n\n");
                inModuleGM = true;
                txtHeadersGM << _T("// Global procedures\n");
            }
            m_Indent = 1;
            BindProcedure(txtBindGM, txtHeadersGM, txtCythonFirst, txtCythonGP, fchen->Item(i), globModName, true);
        }
        else if (fchen->Item(i)->m_TokenKind == tkModule)
        {
            m_InFortranModule = true;
            wxString modName = fchen->Item(i)->m_Name;
            m_CurModule = modName;
            txtBindMod << _T("module ") << modName << _T("_bc\n");
            m_Indent = 1;
            txtBindMod << GetIS() << _T("use :: ") << modName << _T("\n");
            txtBindMod << GetIS() << _T("use, intrinsic :: iso_c_binding\n");
            txtBindMod << _T("$#$#%^@@place for helper module$#@%");
            txtBindMod << GetIS() << _T("implicit none\n");
            txtBindMod << _T("contains\n\n");

            txtHeadersMod << _T("\n// Module '") << modName << _T("' procedures\n");
            m_DefinedTypes.clear();
            m_NoArgConstructors.clear();
            m_Deallocators.clear();
            m_ModuleChildNames.clear();
            m_HasPyClassConstructor = false;

            if (m_PyCreateClass)
            {
                txtCythonMod << _T("\ncdef class ") << modName << _T(":\n");
                txtCythonMod << _T("%%%##@@@@Place For Cdefs%%%@@@");
                txtCythonMod << _T("@@%##@@@@Place For __init__dealloc__%%%@%%");
                m_PyIndent = 1;
            }

            TokensArrayF* mchil = &fchen->Item(i)->m_Children;
            for (size_t j=0; j<mchil->GetCount(); j++)
            {
                if ((mchil->Item(j)->m_TokenKind == tkSubroutine ||
                    mchil->Item(j)->m_TokenKind == tkFunction) &&
                    mchil->Item(j)->m_TokenAccess == taPublic)
                {
                    m_ModuleChildNames.insert(mchil->Item(j)->m_Name);
                }
            }

            for (size_t j=0; j<mchil->GetCount(); j++)
            {
                if ((mchil->Item(j)->m_TokenKind == tkSubroutine ||
                    mchil->Item(j)->m_TokenKind == tkFunction) &&
                    mchil->Item(j)->m_TokenAccess == taPublic)
                {
                    BindProcedure(txtBindMod, txtHeadersMod, txtCythonFirst, txtCythonMod, mchil->Item(j), modName, false);
                    m_ModuleChildNames.insert(mchil->Item(j)->m_Name);
                }
                else if (mchil->Item(j)->m_TokenKind == tkInterfaceExplicit &&
                         mchil->Item(j)->m_TokenAccess == taPublic)
                {
                    TokensArrayF* intchs = &mchil->Item(j)->m_Children;
                    for (size_t k=0; k<intchs->GetCount(); k++)
                    {
                        if ((intchs->Item(k)->m_TokenKind == tkSubroutine ||
                            intchs->Item(k)->m_TokenKind == tkFunction) &&
                            intchs->Item(k)->m_TokenAccess == taPublic)
                        {
                            BindProcedure(txtBindMod, txtHeadersMod, txtCythonFirst, txtCythonMod, intchs->Item(k), modName, false);
                            m_ModuleChildNames.insert(intchs->Item(k)->m_Name);
                        }
                    }
                }
                else if (mchil->Item(j)->m_TokenKind == tkInterface &&
                         mchil->Item(j)->m_TokenAccess == taPublic &&
                         !mchil->Item(j)->m_Name.IsEmpty())
                {
                    TokensArrayF* intchs = &mchil->Item(j)->m_Children;
                    for (size_t k=0; k<intchs->GetCount(); k++)
                    {
                        wxString iname = intchs->Item(k)->m_Name;
                        for (size_t l=0; l<mchil->GetCount(); l++)
                        {
                            if ((mchil->Item(l)->m_TokenKind == tkSubroutine ||
                                mchil->Item(l)->m_TokenKind == tkFunction) &&
                                mchil->Item(l)->m_TokenAccess == taPrivate &&   // items with taPublic are called separately
                                mchil->Item(l)->m_Name.IsSameAs(iname))
                            {
                                BindProcedure(txtBindMod, txtHeadersMod, txtCythonFirst, txtCythonMod, mchil->Item(l), modName, false, mchil->Item(j)->m_DisplayName);
                                m_ModuleChildNames.insert(mchil->Item(l)->m_Name);
                            }
                        }
                    }
                }
                else if (mchil->Item(j)->m_TokenKind == tkType &&
                         mchil->Item(j)->m_TokenAccess == taPublic)
                {
                    m_DefinedTypes.insert(mchil->Item(j)->m_Name);
                }
            }
            wxString txtCythonCtorDtor;
            AddConstructors(txtBindMod, txtHeadersMod, txtCythonCtorDtor, txtCythonFirst, modName);
            AddDestructors(txtBindMod, txtHeadersMod, txtCythonCtorDtor, txtCythonFirst, modName);
            txtBindMod << _T("end module\n\n");
            m_CurModule = wxEmptyString;
            m_InFortranModule = false;
            m_PyIndent = 0;
            if (m_DefinedTypes.size() == 0)
                txtCythonMod.Replace(_T("%%%##@@@@Place For Cdefs%%%@@@"),_T(""));
            else
            {
                wxString txtCythonCdefs;
                for (StrSet::iterator it=m_DefinedTypes.begin(); it!=m_DefinedTypes.end(); ++it)
                {
                    txtCythonCdefs << GetIS(1) << _T("cdef void* _") << *it << _T("_cp\n");
                }
                txtCythonMod.Replace(_T("%%%##@@@@Place For Cdefs%%%@@@"),txtCythonCdefs);
            }

            txtCythonMod.Replace(_T("@@%##@@@@Place For __init__dealloc__%%%@%%"), txtCythonCtorDtor);
        }
    }
    if (inModuleGM && !m_UseOneGlobalFile)
        txtBindGM << _T("end module\n\n");

    wxString helperMod = GetHelperModule();
    if (!helperMod.empty() && !txtBindGM.empty())
        txtBindGM.Replace(_T("$#$#%^@@place for helper module$#@%"),GetIS(1) + _T("use :: bindc_helper_bc\n"));
    else if (!txtBindGM.empty())
        txtBindGM.Replace(_T("$#$#%^@@place for helper module$#@%"),_T(""));

    if (!helperMod.empty() && !txtBindMod.empty())
        txtBindMod.Replace(_T("$#$#%^@@place for helper module$#@%"),GetIS(1) + _T("use :: bindc_helper_bc\n"));
    else if (!txtBindMod.empty())
        txtBindMod.Replace(_T("$#$#%^@@place for helper module$#@%"),_T(""));

    wxString bfname = CreateBindFilename(filename, false);
    if (bfname.IsEmpty())
        return;
    wxString hname = CreateBindFilename(filename, true);
    if (hname.IsEmpty())
        return;

    wxString pyname;
    if (m_PyGenCython)
    {
        pyname = CreateCythonFilename(filename);
        if (pyname.IsEmpty())
            return;
    }

    if (m_UseOneGlobalFile)
    {
        if (!txtBindGM.IsEmpty())
        {
            m_GlobProceduresFile << _T("\n") << txtBindGM;
            m_GlobProcWarnMessages << m_WarnMessage;
        }

        if (!txtHeadersGM.IsEmpty())
            m_GlobProceduresFileH << _T("\n") << txtHeadersGM;

        if (!txtBindMod.IsEmpty())
        {
            wxFile f(bfname, wxFile::write);
            cbWrite(f, m_WarnMessage + SplitLines(helperMod,Fortran) +
                    SplitLines(txtBindMod,Fortran) + GetEOLStr(), wxFONTENCODING_UTF8);
        }

        if (!m_CInclude.empty())
        {
            StrSet::iterator it;
            for (it=m_CInclude.begin(); it != m_CInclude.end(); ++it)
            {
                m_GlobProceduresCInclude.insert(*it);
            }
        }

        if (!m_GlobWriteIntToLog)
            m_GlobWriteIntToLog = m_WriteIntToLog;
        if (!m_GlobWriteLogToInt)
            m_GlobWriteLogToInt = m_WriteLogToInt;
        if (!m_GlobWriteStrCtoF)
            m_GlobWriteStrCtoF = m_WriteStrCtoF;
        if (!m_GlobWriteStrFtoC)
            m_GlobWriteStrFtoC = m_WriteStrFtoC;
        if (!m_GlobWriteStrLen)
            m_GlobWriteStrLen = m_WriteStrLen;

        if (!m_WarnMessage.IsEmpty())
        {
            wxString msg;
            msg << _("\nThere were problems met during the generation of wrapping.");
            msg << _("\nA message was added to the beginning of generated file.");
            m_CreatedMsg.Add(msg);
        }
    }
    else
    {
        wxFile f(bfname, wxFile::write);
        cbWrite(f, m_WarnMessage + SplitLines(helperMod,Fortran) + SplitLines(txtBindGM,Fortran) +
                SplitLines(txtBindMod,Fortran) + GetEOLStr(), wxFONTENCODING_UTF8);

        wxFileName hfname(hname);
        wxString hstr1;
        hstr1 << _T("#ifndef ") << hfname.GetName().Upper() << _T("_H") << _T("\n");
        hstr1 << _T("#define ") << hfname.GetName().Upper() << _T("_H") << _T("\n\n");
        if (!m_CInclude.empty())
        {
            StrSet::iterator it;
            for (it=m_CInclude.begin(); it != m_CInclude.end(); ++it)
                hstr1 << *it << _T("\n");
        }
        wxString hstr2 = _T("\n#endif");

        wxFile hf(hname, wxFile::write);
        cbWrite(hf, hstr1 + m_CStructs + _T("\n") + SplitLines(txtHeadersGM,C) + SplitLines(txtHeadersMod,C) +
                 hstr2 + GetEOLStr(), wxFONTENCODING_UTF8);

        wxString txtCythonHead;
        txtCythonHead << _T("#!python\n#cython: boundscheck=False, wraparound=False\n");
        txtCythonHead << _T("import numpy as np\ncimport numpy as np\n");
        if (!m_PyInclude.empty())
        {
            StrSet::iterator it;
            for (it=m_PyInclude.begin(); it != m_PyInclude.end(); ++it)
                txtCythonHead << *it << _T("\n");
        }
        txtCythonHead << _T("\n");

        txtCythonHead << _T("cdef extern from \"") << hfname.GetFullName() << _T("\":\n");
        wxString pyFiles;
        if (m_PyGenCython)
        {
            wxFile pyxf(pyname, wxFile::write);
            cbWrite(pyxf, txtCythonHead + txtCythonFirst + SplitLines(txtCythonGP,Python) + SplitLines(txtCythonMod,Python) +
                    GetEOLStr(), wxFONTENCODING_UTF8);
            wxFileName pyfn(pyname);
            pyFiles << _T(", ") << pyfn.GetFullName();
        }

        wxFileName bfn(bfname);
        m_CreatedMsg.Add(_("Files ") + bfn.GetFullName() + _T(", ") + hfname.GetFullName() + pyFiles + _(" were created in ")
                         + hfname.GetPath() + _(" folder."));
        if (!m_WarnMessage.IsEmpty())
        {
            m_CreatedMsg.Add(_("\nThere were problems met during the generation of wrapping. A message was added to the beginning of ")
                             +bfn.GetFullName()+_(" file."));
        }
    }
    m_CurFile = wxEmptyString;
}

/** \brief Get Indent Spaces
 *
 * \return wxString Returns required number of spaces
 *
 */
wxString Bindto::GetIS(int nint)
{
    wxString spaces;
    if (nint >= 0)
        return spaces.Append(' ',m_TabSize*nint);
    return spaces.Append(' ',m_TabSize*m_Indent);
}

wxString Bindto::CreateBindFilename(const wxString& filename, bool header)
{
    wxFileName fname(filename);
    fname.SetPath(m_OutputDir);
    if (header)
        fname.SetExt(_T("h"));
    else
    {
        wxString ext = fname.GetExt();
        if (ext != _T("f90") && ext != _T("f95") && ext != _T("f03") && ext != _T("f08"))
            fname.SetExt(_T("f90"));
    }
    wxString name = fname.GetName() << _T("_bc");
    fname.SetName(name);

    return CheckOverwriteFilename(fname);
}

wxString Bindto::CheckOverwriteFilename(wxFileName &fname)
{
    while (fname.FileExists())
    {
        wxString query_overwrite;
        query_overwrite << _("Warning:\n")
           << _("This tool is about OVERWRITE the following existing file:\n")
           << fname.GetFullPath()
           << _("\n\nAre you sure that you want to OVERWRITE the file?\n\n")
           << _("(If you answer 'No' the existing file will be kept.)");
        int answ = cbMessageBox(query_overwrite, _("Confirmation"),
                         wxICON_QUESTION | wxYES_NO | wxNO_DEFAULT);
        if (answ == wxID_NO)
        {
            bool n_changed = false;
            wxString name = fname.GetName();
            wxRegEx reEnd(_T("_([0-9]*$)"));
            if (reEnd.Matches(name))
            {
                // increase file number
                wxString sn = reEnd.GetMatch(name, 1);
                long fn;
                if (sn.ToLong(&fn))
                {
                    fn++;
                    wxString snn;
                    snn << fn;
                    name = name.Mid(0,name.size()-sn.size()) + snn;
                    n_changed = true;
                }
            }

            if (!n_changed)
            {
                name << _T("_1");
            }
            fname.SetName(name);
        }
        else if (answ == wxID_YES)
            break;
        else
            return wxEmptyString;
    }
    return fname.GetFullPath();
}


void Bindto::BindProcedure(wxString& txtBind, wxString& txtHeaders, wxString& txtPyFirst, wxString& txtPySecond,
                           TokenF* token, const wxString& moduleName, bool isGlobal, wxString callName)
{
    m_CurProcedure = token->m_Name;
    wxString txtBindProc;
    wxString txtBindFirst;
    wxString txtBindSecond;
    wxString txtHeadersThis;
    wxString funResVar;
    wxString addFunVariable;
    wxArrayString funInterface;
    wxString cFunResVar;
    wxString funTypeDec;
    wxArrayString additionalDeclar;
    wxArrayString additionalCalls;
    wxArrayString additionalCalls2;
    std::map<wxString,wxString> changedNamesMap;
    wxString procName = token->m_Name + _T("_bc");
    wxString cName = GetCName(token->m_Name, moduleName);
    bool bindKindSubroutine = true;
    if (token->m_TokenKind == tkSubroutine)
        txtBindFirst << GetIS() << _T("subroutine ");
    else if (token->m_TokenKind == tkFunction)
    {
        txtBindFirst << GetIS() << _T("function ");
        bindKindSubroutine = false;
    }
    else
        // what else can token be?
        return;

    wxString txtCythonFirst;
    wxString txtCythonSecond;
    wxString txtCythonSecond2;
    wxString txtCythonSecond3;
    wxArrayString additionalDeclarPy;
    StrSet argHideSetPy;
    wxArrayString pyLines;
    bool nowIsPyConstructor = false;
    bool noArgPyConstructor = false;
    bool nowIsPyDestructor  = false;
    wxString constrTypeName;
    wxString constrProcName;
    wxString txtCythonConstr1;
    wxString txtCythonConstr2;

    txtBindFirst << procName;
    m_Indent++;
    bool wasChlen = false;
    wxArrayString argArr;
    wxStringTokenizer tkz(token->m_Args.Lower(), _T("(),[] \t\r\n"), wxTOKEN_STRTOK );
    while ( tkz.HasMoreTokens() )
        argArr.Add(tkz.GetNextToken());

    txtBindFirst << _T("(");
    for (size_t i=0; i<argArr.GetCount(); i++)
    {
        txtBindFirst << argArr.Item(i);
        if (i+1 < argArr.GetCount())
            txtBindFirst << _T(", ");
    }

    if (token->m_TokenKind == tkFunction)
    {
        funInterface.Add(_T("interface"));
        funInterface.Add(_T("function ") + token->m_Name + token->m_Args.Lower());

        wxString funT = GetFunctionDeclaration(token);
        m_pTokenCurrent = token;
        int itmp;
        TypeBind tys = GetBindType(funT, itmp);
        funTypeDec = tys.fType;
        if (tys.cDim.IsEmpty())
        {
            funResVar = procName;
            txtBindSecond << GetIS() << tys.bType << _T(" :: ") << funResVar << _T("\n");
            txtHeadersThis << tys.cType << _T(" ") << cName << _T("(");
        }
        else
        {
            // If function returns an array, change it to subroutine (void function) with the last array argument.
            bindKindSubroutine = true;
            txtBindFirst.Replace(_T("function"), _T("subroutine"), false);
            funResVar = token->m_Name + _T("_res");
            txtBindSecond << GetIS() << tys.bType << _T(", intent(out) :: ") << funResVar << _T("\n");
            addFunVariable << _T(", ") + funResVar;
            txtHeadersThis << _T("void ") << cName << _T("(");
            cFunResVar = tys.cType + _T(" ") + funResVar + tys.cDim;
        }
        funInterface.Add(funTypeDec + _T(" :: ") + token->m_DisplayName);
        if (funTypeDec.StartsWith(_T("character")))
        {
            additionalDeclar.Add(funTypeDec + _T(" :: ") + funResVar + _T("_f"));
            additionalCalls2.Add(_T("call string_copy_f_c(") + funResVar + _T("_f,") + funResVar + _T(")"));
            m_WriteStrFtoC = true;
        }
        else if (!tys.fType.StartsWith(_T("type(c_ptr)")) && tys.bType.StartsWith(_T("type(c_ptr)")))
        {
            wxString fName = funResVar + _T("_fp");
            additionalDeclar.Add(funTypeDec + _T(", pointer :: ") + fName);
            additionalCalls.Add(_T("allocate(") + fName + _T(")"));
            additionalCalls2.Add(funResVar + _T(" = c_loc(") + fName + _T(")"));
            funResVar = fName;
        }
        else if (tys.fType.StartsWith(_T("logical")) && tys.bType.StartsWith(_T("integer")))
        {
            additionalDeclar.Add(funTypeDec + _T(" :: ") + funResVar + _T("_f"));
            additionalCalls2.Add(funResVar + _T(" = log_to_int(") + funResVar + _T("_f)"));
            changedNamesMap[funResVar] = funResVar + _T("_f");
            m_WriteLogToInt = true;
        }

        wxString pyVarName = token->m_Name + _T("_res");
        TypePyx tyaPy = GetBindTypePy(tys);
        if (tyaPy.fDrvTypeName.IsEmpty())
        {
            wxString pyLin1 = _T("cdef ") + tyaPy.declarPyxFirst + _T(" ") + pyVarName + _T(" = ") + cName + _T("(");
            pyLines.Add(pyLin1);
        }
        else if (m_InFortranModule && m_PyCreateClass && !m_HasPyClassConstructor && IsConstructor(token) && m_DefinedTypes.count(tyaPy.fDrvTypeName) == 1)
        {
            nowIsPyConstructor = true;
            m_HasPyClassConstructor = true;
            constrTypeName = tyaPy.fDrvTypeName;
            if (argArr.GetCount() == 0)
            {
                noArgPyConstructor = true;
                m_NoArgConstructors.insert(funTypeDec);
            }
            wxString pyLin1 = _T("self._") + tyaPy.fDrvTypeName + _T("_cp = ") + cName + _T("(");
            pyLines.Add(pyLin1);
            pyVarName = _T("");
        }
        else
        {
            wxString pyClassName;
            wxArrayString address;
            m_pParser->GetAddress(token, address);
            TokensArrayFlatClass tokensTmp;
            TokensArrayFlat* resultTmp = tokensTmp.GetTokens();
            m_pParser->FindUseAssociatedTokens(true, address, tyaPy.fDrvTypeName, false, *resultTmp, tkType, false);
            if (resultTmp->size() > 0 && resultTmp->Item(0)->m_ParentTokenKind == tkModule)
            {
                pyClassName = resultTmp->Item(0)->m_ParentName;
            }
            wxString pyLin1 = _T("cdef ") + pyClassName + _T(" ") + pyVarName + _T(" = ") + pyClassName + _T("()\n");
            pyLines.Add(pyLin1);
            pyLin1 = pyVarName + _T(".") + tyaPy.fDrvTypeName + _T("_cp_del_py()\n");
            pyLines.Add(pyLin1);
            pyLin1 = pyVarName + _T("._") + tyaPy.fDrvTypeName + _T("_cp") + _T(" = ") + cName + _T("(");
            pyLines.Add(pyLin1);

            if (IsConstructor(token) && m_DefinedTypes.count(tyaPy.fDrvTypeName) == 1 && argArr.GetCount() == 0)
                m_NoArgConstructors.insert(funTypeDec);
        }
        txtCythonSecond3 = pyVarName;
    }
    else if (token->m_TokenKind == tkSubroutine)
    {
        txtHeadersThis << _T("void ") << cName << _T("(");

        wxString pyLin1 = cName + _T("(");
        pyLines.Add(pyLin1);
    }

    wxString pyName = GetPyName(token->m_Name, moduleName);
    if (nowIsPyConstructor)
    {
        if (noArgPyConstructor)
        {
            txtCythonSecond << _T("\n") << GetIS(m_PyIndent) << _T("def __cinit__(self");
        }
        else
        {
            txtCythonConstr1 << _T("\n") << GetIS(m_PyIndent) << _T("def __cinit__(self");
            if ((token->m_TokenKind == tkSubroutine && argArr.GetCount() > 1) ||
                (token->m_TokenKind == tkFunction && argArr.GetCount() > 0))
                txtCythonConstr1 << _T(", ");

            txtCythonSecond << _T("\n") << GetIS(m_PyIndent) << _T("cdef ") << pyName << _T("(self");
            if ((token->m_TokenKind == tkSubroutine && argArr.GetCount() > 1) ||
                (token->m_TokenKind == tkFunction && argArr.GetCount() > 0))
                txtCythonSecond << _T(", ");
            constrProcName = pyName;
        }
    }
    else
    {
        txtCythonSecond << _T("\n") << GetIS(m_PyIndent) << _T("def ") << pyName << _T("(");
        if (m_InFortranModule && m_PyCreateClass)
        {
            txtCythonSecond << _T("self");
            if (argArr.GetCount() > 0)
                txtCythonSecond << _T(", ");
        }
    }
    m_PyIndent++;
    for (size_t i=0; i<pyLines.GetCount(); i++)
    {
        txtCythonSecond2 << GetIS(m_PyIndent) << pyLines.Item(i);
    }

    wxArrayString dimVarNames;
    wxArrayString dimVarNamesFP;
    wxArrayString varNamesOfDim;
    wxArrayString varNamesOfDimFP;
    for (size_t i=0; i<argArr.GetCount(); i++)
    {
        if (i > 0)
        {
            txtHeadersThis << _T(", ");
            txtCythonSecond << _T(", ");
            txtCythonSecond2 << _T(", ");
            txtCythonConstr1 << _T(", ");
            txtCythonConstr2 << _T(", ");
        }
        bool usedSelfPy = false;
        TokenF* argToken = m_pParser->FindTokenBetweenChildren(token, argArr.Item(i));
        if (!argToken)
        {
            // Should implicit declaration be assumed?
            txtHeadersThis << argArr.Item(i);
            continue;
        }

        if (argToken->m_TokenKind == tkVariable)
        {
            m_pTokenCurrent = argToken;
            int nDimVarAdd;
            TypeBind tys = GetBindType(argToken, nDimVarAdd);
            if (nDimVarAdd > 0)
                AddDimVariablesFromDoc(dimVarNames, nDimVarAdd, argToken->m_DocString, argToken->m_Name, varNamesOfDim);
            if (nDimVarAdd > 0)
                AddDimVariables(argArr, dimVarNames, nDimVarAdd, _T("m"), argToken->m_Name, varNamesOfDim);

            if (!tys.fType.StartsWith(_T("type(c_ptr)")) && tys.bType.StartsWith(_T("type(c_ptr)")))
            {
                wxString fDec = tys.fType;
                if (fDec.StartsWith(_T("class(")))
                    fDec.Replace(_T("class("), _T("type("), false);
                fDec.Replace(_T(", intent(in)"),_T(""));
                fDec.Replace(_T(", intent(out)"),_T(""));
                fDec.Replace(_T(", intent(inout)"),_T(""));
                wxString bvName = argToken->m_Name + _T("_fp");

                if (IsConstructor(token) && token->m_TokenKind == tkSubroutine && i == 0 && m_DefinedTypes.count(argToken->m_Name) == 1)
                {
                    additionalCalls.Add(_T("allocate(") + bvName + _T(")"));
                    additionalCalls.Add(argToken->m_Name + _T(" = c_loc(") + bvName + _T(")"));
                    if (argArr.GetCount() == 1)
                        m_NoArgConstructors.insert(fDec);
                }
                else
                {
                    wxString fDecHid;
                    int nAD;
                    HideAssumedShape(fDec, fDecHid, nAD);
                    if (nAD > 0)
                    {
                        size_t nVNini = dimVarNamesFP.size();
                        AddDimVariablesFromDoc(dimVarNamesFP, nAD, argToken->m_DocString, argToken->m_Name, varNamesOfDimFP);
                        if (nAD > 0)
                            AddDimVariables(argArr, dimVarNamesFP, nAD, _T("mdt"), argToken->m_Name, varNamesOfDimFP);

                        wxString varShape = _T(", [");
                        for (size_t ivn = nVNini; ivn<dimVarNamesFP.size(); ivn++)
                        {
                            varShape << dimVarNamesFP.Item(ivn) << _T(",");
                        }
                        varShape = varShape.Mid(0,varShape.size()-1) + _T("]");
                        additionalCalls.Add(_T("call c_f_pointer(") + argToken->m_Name + _T(", ") + bvName + varShape + _T(")"));
                    }
                    else
                        additionalCalls.Add(_T("call c_f_pointer(") + argToken->m_Name + _T(", ") + bvName + _T(")"));

                    wxString ftname;
                    if (fDec.size() > 6)
                        ftname = fDec.Mid(5,fDec.size()-6).Trim(true).Trim(false);

                    if (IsDestructor(token) && token->m_TokenKind == tkSubroutine && i == 0 && argArr.GetCount() == 1 &&
                        m_DefinedTypes.count(ftname) == 1)
                    {
                        additionalCalls2.Add(_T("deallocate(") + bvName + _T(")"));
                        if (m_Deallocators.count(ftname) == 0)
                            m_Deallocators[ftname] = cName;
                        nowIsPyDestructor = true;
                    }
                }

                additionalDeclar.Add(fDec + _T(", pointer :: ") + bvName);
                changedNamesMap[argToken->m_Name] = bvName;
            }
            else if (tys.fType.StartsWith(_T("character")))
            {
                //character(len=:), allocatable :: fname_f

                if (tys.fType.Find(_T("len=*")) != wxNOT_FOUND)
                {
                    wxString fDec = tys.fType;
                    fDec.Replace(_T(", intent(in)"),_T(""));
                    fDec.Replace(_T(", intent(out)"),_T(""));
                    fDec.Replace(_T(", intent(inout)"),_T(""));
                    wxString str = fDec + _T(", allocatable :: ") + argToken->m_Name + _T("_f");
                    str.Replace(_T("len=*"), _T("len=:"));
                    additionalDeclar.Add(str);
                    if (!wasChlen)
                    {
                        additionalDeclar.Add(_T("integer :: chlen_bc"));
                        wasChlen = true;
                    }
                    additionalCalls.Add(_T("chlen_bc = string_len(") + argToken->m_Name + _T(")"));
                    additionalCalls.Add(_T("allocate(character(len=chlen_bc)::") + argToken->m_Name + _T("_f)"));
                    m_WriteStrLen = true;
                }
                else
                    additionalDeclar.Add(tys.fType + _T(" :: ") + argToken->m_Name + _T("_f") + argToken->m_Args.Lower());
                if (tys.fType.Find(_T("intent(out)")) == wxNOT_FOUND)
                {
                    additionalCalls.Add(_T("call string_copy_c_f(") + argToken->m_Name + _T(", ") + argToken->m_Name + _T("_f)"));
                    m_WriteStrCtoF = true;
                }
                if (tys.fType.Find(_T("intent(in)")) == wxNOT_FOUND)
                {
                    additionalCalls2.Add(_T("call string_copy_f_c(") + argToken->m_Name + _T("_f, ") + argToken->m_Name + _T(")"));
                    m_WriteStrFtoC = true;
                }
                changedNamesMap[argToken->m_Name] = argToken->m_Name + _T("_f");
            }
            else if (tys.fType.StartsWith(_T("logical")) && tys.bType.StartsWith(_T("integer")))
            {
                wxString fDec = tys.fType;
                fDec.Replace(_T(", intent(in)"),_T(""));
                fDec.Replace(_T(", intent(out)"),_T(""));
                fDec.Replace(_T(", intent(inout)"),_T(""));
                wxString bvName = argToken->m_Name + _T("_f");
                wxString fDecHid;
                int nAD;
                HideAssumedShape(fDec, fDecHid, nAD);
                if (nAD > 0)
                {
                    AddDimVariablesFromDoc(dimVarNames, nAD, argToken->m_DocString, argToken->m_Name, varNamesOfDim);
                    if (nAD > 0)
                        AddDimVariables(argArr, dimVarNames, nAD, _T("mdt"), argToken->m_Name, varNamesOfDim);
                }

                additionalDeclar.Add(fDec + _T(" :: ") + bvName);
                if (tys.fType.Find(_T("intent(out)")) == wxNOT_FOUND)
                {
                    additionalCalls.Add(bvName + _T(" = int_to_log(") + argToken->m_Name + _T(")"));
                    m_WriteIntToLog = true;
                }
                if (tys.fType.Find(_T("intent(in)")) == wxNOT_FOUND)
                {
                    additionalCalls2.Add(argToken->m_Name + _T(" = log_to_int(") + bvName + _T(")"));
                    m_WriteLogToInt = true;
                }
                changedNamesMap[argToken->m_Name] = bvName;
            }
            txtBindSecond << GetIS() << tys.bType << _T(" :: ") << argToken->m_Name;
            txtHeadersThis << tys.cType << _T(" ") << argToken->m_Name << tys.cDim;
            funInterface.Add(tys.fType + _T(" :: ") + argToken->m_Name);

            TypePyx tyaPy = GetBindTypePy(tys);
            if (tyaPy.fDrvTypeName.IsEmpty())
            {
                if (tyaPy.hide)
                {
                    additionalDeclarPy.Add(_T("cdef ") + tyaPy.declarPyxFirst + _T(" ") + argToken->m_Name + tyaPy.initStr);
                    if (txtCythonSecond.EndsWith(_T(", ")))
                        txtCythonSecond.Truncate(txtCythonSecond.size()-2);
                    argHideSetPy.insert(argToken->m_Name);
                }
                else
                    txtCythonSecond << tyaPy.declarPyxFirst << _T(" ") << argToken->m_Name;
                txtCythonSecond2 << _T("&") << argToken->m_Name << tyaPy.callCSecond;
            }
            else
            {
                if (i == 0 && m_PyFirstArgAsSelf && m_InFortranModule && m_PyCreateClass &&
                    (m_DefinedTypes.count(tyaPy.fDrvTypeName) == 1))
                {
                    txtCythonSecond.Truncate(txtCythonSecond.size()-2);
                    txtCythonSecond2 << _T("&self._") << tyaPy.fDrvTypeName << _T("_cp");
                    usedSelfPy = true;
                }
                else
                {
                    wxString pyClassName;
                    wxArrayString address;
                    m_pParser->GetAddress(token, address);
                    TokensArrayFlatClass tokensTmp;
                    TokensArrayFlat* resultTmp = tokensTmp.GetTokens();
                    m_pParser->FindUseAssociatedTokens(true, address, tyaPy.fDrvTypeName, false, *resultTmp, tkType, false);
                    if (resultTmp->size() > 0 && resultTmp->Item(0)->m_ParentTokenKind == tkModule)
                    {
                        pyClassName = resultTmp->Item(0)->m_ParentName;
                    }
                    txtCythonSecond << pyClassName << _T(" ") << argToken->m_Name;
                    txtCythonSecond2 << _T("&") << argToken->m_Name << _T("._") << tyaPy.fDrvTypeName << _T("_cp");
                }
            }

            if (!tyaPy.intent.IsEmpty() && !usedSelfPy)
            {
                if (!txtCythonSecond3.IsEmpty())
                    txtCythonSecond3 << _T(", ");
                txtCythonSecond3 << argToken->m_Name;
            }

            if (nowIsPyConstructor && !noArgPyConstructor)
            {
                txtCythonConstr1 << argToken->m_Name << _T("=None");
                if ((i == 0 && token->m_TokenKind == tkFunction) ||
                    (i == 1 && token->m_TokenKind == tkSubroutine))
                {
                    txtCythonConstr2 << GetIS(m_PyIndent) << _T("if ") << argToken->m_Name << _T(" is not None:\n");
                    txtCythonConstr2 << GetIS(m_PyIndent+1) << _T("self.") << constrProcName << _T("(");
                    txtCythonConstr2 << argToken->m_Name;
                }
                else
                {
                    txtCythonConstr2 << argToken->m_Name;
                }
            }

        }
        else
        {
            // it may be a procedure. What then to do?
        }
        txtBindSecond << _T("\n");

    }
    // Deal with assumed-shape arrays
    wxArrayString addVarNames;
    wxArrayString addVarNamesC;
    wxArrayString addVarNamesPy;
    wxArrayString addArgNamesPy;
    wxArrayString additionalDeclarPy_tmp;
    wxArrayString addVarNamesPy_tmp;
    StrSet argHideSetPy_tmp;
    wxArrayString addArgNamesPy_tmp;
    PrepareAssumedShapeVariables(txtBindSecond, argArr, dimVarNames, additionalDeclar, addVarNames, addVarNamesC, varNamesOfDim,
                                 argHideSetPy, additionalDeclarPy, addVarNamesPy, addArgNamesPy);
    PrepareAssumedShapeVariables(txtBindSecond, argArr, dimVarNamesFP, additionalDeclar, addVarNames, addVarNamesC, varNamesOfDimFP,
                                 argHideSetPy_tmp, additionalDeclarPy_tmp, addVarNamesPy_tmp, addArgNamesPy_tmp);
    for (size_t i=0; i<addVarNames.size(); i++)
        txtBindFirst << _T(", ") << addVarNames.Item(i);

    txtBindFirst << addFunVariable;
    txtBindFirst << _T(") bind(c,name='") << cName << _T("')\n");

    for (size_t i=0; i<addVarNamesC.size(); i++)
        txtHeadersThis << _T(", ") << addVarNamesC.Item(i);
    if (token->m_TokenKind == tkFunction && bindKindSubroutine)
        txtHeadersThis << _T(", ") << cFunResVar;

    if (isGlobal && token->m_TokenKind == tkFunction)
    {
        if (bindKindSubroutine)
        {
            funInterface.Add(_T("end function"));
            funInterface.Add(_T("end interface"));

            txtBindSecond << _T("\n");
            for (size_t i=0; i<funInterface.size(); i++)
            {
                if (i==1 || i==2)
                    m_Indent++;
                else if (i==funInterface.size()-2 || i==funInterface.size()-1)
                    m_Indent--;
                txtBindSecond << GetIS() << funInterface.Item(i) << _T("\n");
            }
        }
        else
            txtBindSecond << GetIS() << funTypeDec << _T(" :: ") << token->m_DisplayName << _T("\n");
    }

    for (size_t i=0; i<additionalDeclar.size(); i++)
        txtBindSecond << GetIS() << additionalDeclar.Item(i) << _T("\n");

    txtBindSecond << _T("\n");
    txtHeadersThis << _T(");\n");
    txtCythonFirst << GetIS(1) << txtHeadersThis.Mid(0,txtHeadersThis.size()-2) << _T("\n");
    for (size_t i=0; i<additionalCalls.size(); i++)
        txtBindSecond << GetIS() << additionalCalls.Item(i) << _T("\n");

    if (callName.IsEmpty())
        callName = token->m_DisplayName;
    if (token->m_TokenKind == tkSubroutine)
    {
        txtBindSecond << GetIS() << _T("call ") << callName << _T("(");
    }
    else if (token->m_TokenKind == tkFunction)
    {
        if (funTypeDec.StartsWith(_T("character")))
            txtBindSecond << GetIS() << funResVar << _T("_f = ") << callName << _T("(");
        else if (changedNamesMap.count(funResVar) == 0)
            txtBindSecond << GetIS() << funResVar << _T(" = ") << callName << _T("(");
        else
            txtBindSecond << GetIS() << changedNamesMap[funResVar] << _T(" = ") << callName << _T("(");
    }

    for (size_t i=0; i<argArr.GetCount(); i++)
    {
        if (changedNamesMap.count(argArr.Item(i)) == 0)
            txtBindSecond << argArr.Item(i);
        else
            txtBindSecond << changedNamesMap[argArr.Item(i)];
        if (i+1 < argArr.GetCount())
            txtBindSecond << _T(", ");
    }
    txtBindSecond << _T(")\n");

    for (size_t i=0; i<additionalCalls2.size(); i++)
        txtBindSecond << GetIS() << additionalCalls2.Item(i) << _T("\n");

    m_Indent--;
    if (bindKindSubroutine)
        txtBindSecond << GetIS() << _T("end subroutine\n\n");
    else
        txtBindSecond << GetIS() << _T("end function\n\n");
    txtBind << txtBindFirst << txtBindSecond;
    txtHeaders << txtHeadersThis;


    if (nowIsPyConstructor && !noArgPyConstructor)
    {
        txtCythonConstr1 << _T("):\n");
        txtCythonConstr2 << _T(")\n");
        for ( StrSet::iterator it=m_DefinedTypes.begin(); it != m_DefinedTypes.end(); ++it)
        {
            wxString type = *it;
            if (constrTypeName.IsSameAs(*it))
                continue;
            wxString conName = GetConstructorName(type);
            wxString cConName = GetCName(conName, moduleName);
            txtCythonConstr2 << GetIS(m_PyIndent+1) << _T("self._") << type << _T("_cp = ") << cConName << _T("()\n");
        }
        txtCythonConstr2 << GetIS(m_PyIndent) << _T("else:\n");
        for ( StrSet::iterator it=m_DefinedTypes.begin(); it != m_DefinedTypes.end(); ++it)
        {
            wxString type = *it;
            wxString conName = GetConstructorName(type);
            wxString cConName = GetCName(conName, moduleName);
            txtCythonConstr2 << GetIS(m_PyIndent+1) << _T("self._") << type << _T("_cp = ") << cConName << _T("()\n");
        }
    }

    wxString txtCythonMore1;
    for (size_t i=0; i<additionalDeclarPy.size(); i++)
        txtCythonMore1 << GetIS(m_PyIndent) << additionalDeclarPy.Item(i) << _T("\n");
    for (size_t i=0; i<addArgNamesPy.size(); i++)
        txtCythonSecond << _T(", ") << addArgNamesPy.Item(i);
    txtCythonSecond << _T("):\n");
    txtCythonSecond << txtCythonMore1;
    for (size_t i=0; i<addVarNamesPy.size(); i++)
        txtCythonSecond2 << _T(", ") << addVarNamesPy.Item(i);
    txtCythonSecond2 << _T(")\n");
    txtCythonSecond << txtCythonSecond2;
    if (!txtCythonSecond3.IsEmpty())
        txtCythonSecond << GetIS(m_PyIndent) << _T("return ") << txtCythonSecond3 << _T("\n");

    if (nowIsPyConstructor && !noArgPyConstructor)
    {
        txtCythonSecond << txtCythonConstr1;
        txtCythonSecond << txtCythonConstr2;
    }
    else if (nowIsPyDestructor)
        txtCythonSecond.clear();

    txtPyFirst << txtCythonFirst;
    txtPySecond << txtCythonSecond;
    m_PyIndent--;

    m_CurProcedure = wxEmptyString;
}


Bindto::TypeBind Bindto::GetBindType(TokenF* token, int& nDimVarAdd)
{
    nDimVarAdd = 0;
    TypeBind retSt = GetBindType(token->m_TypeDefinition.Lower(), nDimVarAdd);
    if (token->m_Args.StartsWith(_T("(")))
    {
        wxString vDim = GetToken(token->m_Args.Lower(),0);
        wxString vDimHid;
        int nAssumedDim;
        HideAssumedShape(vDim, vDimHid, nAssumedDim);
        if (retSt.fType.Find(_T("dimension(")) == wxNOT_FOUND)
        {
            int itn = retSt.fType.Find(_T(", intent("));
            int itn2 = retSt.bType.Find(_T(", intent("));
            if (itn == wxNOT_FOUND || itn2 == wxNOT_FOUND)
            {
                retSt.fType << _T(", dimension") << vDim;
                if (retSt.fType.StartsWith(_T("type(c_ptr)")) || !retSt.bType.StartsWith(_T("type(c_ptr)")))
                    retSt.bType << _T(", dimension") << vDimHid;
            }
            else
            {
                retSt.fType.insert(itn,_T(", dimension")+vDim);
                if (retSt.fType.StartsWith(_T("type(c_ptr)")) || !retSt.bType.StartsWith(_T("type(c_ptr)")))
                    retSt.bType.insert(itn2,_T(", dimension")+vDimHid);
            }
            nDimVarAdd = nAssumedDim;
        }
        else
        {
            int idxDim = retSt.fType.Find(_T("dimension("));
            wxString vdimOld;
            if (idxDim != wxNOT_FOUND)
                vdimOld = GetToken(retSt.fType,idxDim+9);
            int idxDim2 = retSt.bType.Find(_T("dimension("));
            wxString vdimOld2;
            if (idxDim2 != wxNOT_FOUND)
                vdimOld2 = GetToken(retSt.bType,idxDim2+9);
            retSt.fType.Replace(vdimOld,vDim);
            if (!vdimOld2.IsEmpty())
                retSt.bType.Replace(vdimOld2,vDimHid);
            nDimVarAdd = nAssumedDim;
        }
        retSt.cDim = GetCDims(vDim);
    }

    if (retSt.cDim.IsEmpty())
        retSt.cType << _T("*"); // variable as C pointer

    return retSt;
}


Bindto::TypeBind Bindto::GetBindType(const wxString& declar, int& nDimVarAdd)
{
    wxString declarLw = declar.Lower();
    declarLw.Replace(_T(" "),_T(""));
    nDimVarAdd = 0;
    wxString ftype;
    wxString fCharLen;
    wxArrayString fTypeKind = GetTypeAndKind(declarLw);

    if (declarLw.StartsWith(_T("character")))
    {
        // deal with character type
        wxString klstr = fTypeKind.Item(1);
        int iLen = klstr.Find(_T("len="));
        int iKin = klstr.Find(_T("kind="));
        if (iLen != wxNOT_FOUND)
        {
            int lnd = klstr.Mid(iLen+4).Find(_T(","));
            if (lnd == wxNOT_FOUND)
            {
                lnd = klstr.Mid(iLen+4).Find(_T(")"));
                if (lnd == wxNOT_FOUND)
                    lnd = klstr.size();
            }
            fCharLen = klstr.Mid(iLen+4,lnd);
        }
        else if (iKin == wxNOT_FOUND)
        {
            fCharLen = klstr;
        }
        else // (iKin != wxNOT_FOUND)
        {
            fCharLen = _T("1");
        }

        wxString fCharKind;
        if (iKin != wxNOT_FOUND)
        {
            int lnd = klstr.Mid(iKin+5).Find(_T(","));
            if (lnd == wxNOT_FOUND)
            {
                lnd = klstr.size()-iKin-6;
            }
            fCharKind = klstr.Mid(iKin+5,lnd);
        }
        if (fCharKind.IsEmpty())
            ftype = _T("character");
        else
            ftype = _T("character(kind=") + fCharKind + _T(")");
    }
    else
    {
        ftype = fTypeKind.Item(0);
        fTypeKind.Item(1).Replace(_T("kind="),_T(""));
        if (!fTypeKind.Item(1).IsEmpty())
            ftype << _T("(") << fTypeKind.Item(1) << _T(")");
    }

    TypeBind retSt;
    bool wasNotFound = false;
    if (m_TypeMap.count(ftype) == 0)
    {
        wasNotFound = true;
        if (ftype.StartsWith(_T("type(")) || ftype.StartsWith(_T("class(")))
        {
            int st = ftype.Find('(');
            int en = ftype.Find(')');
            if (st != wxNOT_FOUND && en != wxNOT_FOUND)
            {
                wxString tname = ftype.Mid(st+1,en-st-1);
                wxArrayString address;
                m_pParser->GetAddress(m_pTokenCurrent->m_pParent, address);
                TokensArrayFlatClass tokensTmp;
                TokensArrayFlat* resultTmp = tokensTmp.GetTokens();
                m_pParser->FindUseAssociatedTokens(true, address, tname, false, *resultTmp, tkType, false);
                if (resultTmp->size() > 0)
                {
                    TokenF* typeTok = m_pParser->FindToken(resultTmp->Item(0));
                    if (typeTok)
                    {
                        wxString tdef = typeTok->m_TypeDefinition.Lower();
                        tdef.Replace(_T(" "),_T(""));
                        if (tdef.Find(_T("bind(c)")) != wxNOT_FOUND)
                        {
                            // type with bind(c)
                            wxArrayString ct;
                            ct.Add(ftype);
                            wxString c_type;
                            if (en>st)
                                c_type = ftype.Mid(st+1,en-st-1);
                            else
                                c_type = ftype; // something gone wrong
                            ct.Add(c_type);
                            m_TypeMap[ftype] = ct;
                            wasNotFound = false;

                            m_CStructs << _T("\ntypedef struct {\n");
                            TokensArrayF* pChildren = &typeTok->m_Children;
                            for (size_t i=0; i<pChildren->GetCount(); i++)
                            {
                                if (pChildren->Item(i)->m_TokenKind == tkVariable)
                                {
                                    int itmp;
                                    TypeBind bindT = GetBindType(pChildren->Item(i), itmp);
                                    m_CStructs << GetIS(1);
                                    m_CStructs << bindT.cType << _T(" ") << pChildren->Item(i)->m_Name << bindT.cDim[3];
                                    m_CStructs << _T("\n");
                                }
                            }
                            m_CStructs << _T("} ") << typeTok->m_Name << _T(";\n");
                        }
                        else
                        {
                            // type without bind(c)
                            wxArrayString ct;
                            ct.Add(_T("type(c_ptr)"));
                            ct.Add(_T("void*"));
                            m_TypeMap[ftype] = ct;
                            wasNotFound = false;
                        }
                    }
                }
            }
        }
    }

    if (wasNotFound)
    {
        if (m_NotFoundTypes.count(ftype) == 0)
        {
            m_WarnMessage << _("ERROR: Fortran type '") << ftype << _("' was not found between bind types.\n");
            m_WarnMessage << _("File: ") << m_CurFile;
            if (!m_CurModule.IsEmpty())
                m_WarnMessage << _("; Module: ") << m_CurModule;
            m_WarnMessage << _("; Procedure: ") << m_CurProcedure << _T("\n");
            m_NotFoundTypes.insert(ftype);
        }
        TypeBind emptSt;
        emptSt.fType = ftype;
        return emptSt;
    }
    else
    {
        wxArrayString retArr = m_TypeMap[ftype]; //size==2
        retSt.bType = retArr[0];
        retSt.cType = retArr[1];
        retSt.fType = ftype;
        retSt.cDim = wxEmptyString;
    }

    if (retSt.cType.StartsWith(_T("int8_t")) ||
        retSt.cType.StartsWith(_T("int16_t")) ||
        retSt.cType.StartsWith(_T("int32_t")) ||
        retSt.cType.StartsWith(_T("int64_t")))
    {
        m_CInclude.insert(_T("#include <stdint.h>"));
        m_PyInclude.insert(_T("from libc.stdint cimport *"));
    }
    else if (retSt.cType.StartsWith(_T("float complex")) ||
             retSt.cType.StartsWith(_T("double complex")))
    {
        m_CInclude.insert(_T("#include <complex.h>"));
    }

    int iPos = declarLw.Find(_T("dimension("));
    if (iPos != wxNOT_FOUND)
    {
        wxString vdim = GetToken(declarLw,iPos+9);
        retSt.fType << _T(", dimension") << vdim;
        int nAssumedDim;
        wxString vdimHid;
        HideAssumedShape(vdim, vdimHid, nAssumedDim);
        if (!retSt.fType.StartsWith(_T("type(c_ptr)")) && retSt.bType.StartsWith(_T("type(c_ptr)")))
            ;
        else
        {
            retSt.bType << _T(", dimension") << vdimHid;
            retSt.cDim << GetCDims(vdim);
            nDimVarAdd += nAssumedDim;
        }
    }

    if (retSt.fType.StartsWith(_T("character(")))
    {
        int pos = retSt.fType.Find(')',true);
        if (pos != wxNOT_FOUND)
            retSt.fType = retSt.fType.Mid(0,pos) + _T(",len=")+fCharLen+_T(")");
    }
    else if (retSt.fType.StartsWith(_T("character")))
    {
        retSt.fType.Replace(_T("character"), _T("character(len=")+fCharLen+_T(")"));
    }

    if (retSt.fType.StartsWith(_T("character")))
    {
        long numCharLen;
        wxString cDim;
        if (fCharLen.ToLong(&numCharLen))
        {
            fCharLen = wxString::Format(_T("%d"),numCharLen+1);
            cDim = GetCDims(_T("(")+fCharLen+_T(")"));
        }
        else if (!fCharLen.IsSameAs(_T("*")))
        {
            fCharLen << _T("+1");
            cDim = _T("");
        }
        else
            cDim = _T("");
        retSt.bType << _T(", dimension") << _T("(") << fCharLen << _T(")");
        retSt.cDim << cDim;
    }

    iPos = declarLw.Find(_T("intent("));
    if (iPos != wxNOT_FOUND)
    {
        wxString vinout = GetToken(declarLw,iPos+6);
        retSt.fType << _T(", intent") << vinout;
        retSt.bType << _T(", intent") << vinout;
    }
    return retSt;
}

wxArrayString Bindto::GetTypeAndKind(wxString decl)
{
    wxArrayString fTK;
    fTK.Add(_T(""),2);
    decl.Replace(_T(" "), _T(""));
    wxStringTokenizer tokenizer(decl, _T("(*,"), wxTOKEN_STRTOK);
    if (tokenizer.CountTokens() == 0)
        return fTK;
    else if (tokenizer.CountTokens() == 1)
        fTK.Item(0) = tokenizer.GetNextToken();
    else
    {
        fTK.Item(0) = tokenizer.GetNextToken();
        wxChar delim = tokenizer.GetLastDelimiter();
        if (delim == '(')
        {
            size_t pos = tokenizer.GetPosition() - 1;
            wxString ks = GetToken(decl,pos);
            fTK.Item(1) = ks.Mid(1,ks.size()-2);
        }
        else if (delim == '*')
        {
            wxString kind = tokenizer.GetNextToken();
            if (fTK.Item(0).IsSameAs(_T("complex")))
                fTK.Item(0) << _T("*") << kind;
            else
                fTK.Item(1) = kind;
        }
    }
    return fTK;
}

wxString Bindto::GetFunctionDeclaration(TokenF* token)
{
    wxString funType;
    if (!token->m_PartFirst.IsEmpty())
    {
        wxString strLw = token->m_PartFirst.Lower().Trim(true).Trim(false);
        strLw.Replace(_T(" "),_T(""));
        wxArrayString ftarr;
        ftarr.Add(_T("integer("));
        ftarr.Add(_T("real("));
        ftarr.Add(_T("doubleprecision("));
        ftarr.Add(_T("complex("));
        ftarr.Add(_T("logical("));
        ftarr.Add(_T("type("));
        ftarr.Add(_T("class("));
        for (size_t i=0; i<ftarr.size(); i++)
        {
            int iPos = strLw.Find(ftarr.Item(i));
            if (iPos != wxNOT_FOUND)
            {
                int tl = ftarr.Item(i).Length()-1;
                wxString vkind = GetToken(strLw,iPos+tl);
                vkind.Replace(_T("kind="),_T(""));
                funType << ftarr.Item(i).Mid(0,tl);
                funType << vkind;
                return funType;
            }
        }
        ftarr.Empty();
        ftarr.Add(_T("integer"));
        ftarr.Add(_T("real"));
        ftarr.Add(_T("doubleprecision"));
        ftarr.Add(_T("complex"));
        ftarr.Add(_T("logical"));
        for (size_t i=0; i<ftarr.size(); i++)
        {
            int iPos = strLw.Find(ftarr.Item(i));
            if (iPos != wxNOT_FOUND)
            {
                funType << ftarr.Item(i);
                return funType;
            }
        }
    }

    for (int i=0; i<2; i++)
    {
        wxString resVName;
        if (i == 0)
        {
            if(!token->m_ResultVariable.IsEmpty())
                resVName = token->m_ResultVariable;
            else
                continue;
        }
        else
            resVName = token->m_Name;

        TokenF* argToken = m_pParser->FindTokenBetweenChildren(token, resVName);
        if (argToken)
        {
            if (argToken->m_TokenKind == tkVariable)
            {
                m_pTokenCurrent = argToken;
                int itmp;
                TypeBind tys = GetBindType(argToken, itmp);
                funType = tys.fType;
                if (!argToken->m_Args.IsEmpty())
                {
                    funType << _T(", dimension") << argToken->m_Args.Lower();
                }
                break;
            }
        }
        else
        {
            // assume implicit declaration
        }
    }
    return funType;
}


wxString Bindto::GetToken(const wxString& txt, int iPos)
{
    wxChar openChar;
    wxChar closeChar;
    if (txt.GetChar(iPos) == '(')
    {
        openChar = '(';
        closeChar = ')';
    }
    else
        return wxEmptyString;

    wxString retTxt;
    int level = 1;
    for (size_t i=iPos+1; i<txt.Length(); i++)
    {
        if (txt.GetChar(i) == openChar)
            level++;
        else if (txt.GetChar(i) == closeChar)
        {
            level--;
            if (level == 0)
            {
                retTxt << txt.Mid(iPos, i-iPos+1);
                break;
            }
        }
    }
    return retTxt;
}

wxString Bindto::GetCDims(wxString vdim)
{
    //input: (*), (10),    (10,5)  (5,*), (5,3,*), (m,n), (size(a,2),n), (:,:)
    //output: "", "[10]", "[5][10]", "",   "",        "",        "",      ""

    if (vdim.Find(_T("size(")) != wxNOT_FOUND)
        return _T("");

    wxArrayString dimArr;
    wxStringTokenizer tkz(vdim, _T("(), "), wxTOKEN_STRTOK );
    while ( tkz.HasMoreTokens() )
    {
        dimArr.Add(tkz.GetNextToken());
    }

    wxString cdims;
    for (int i=dimArr.GetCount()-1; i>=0; i--)
    {
        wxString ds = dimArr.Item(i);
        long dl;
        if (!ds.ToLong(&dl))
            return _T("");
        else
            cdims << _T("[") << ds << _T("]");
    }
    return cdims;
}


void Bindto::OnAdd(wxCommandEvent& event)
{
    BindtoNewType addNewType(this);
    ShowNewTypeDlg(addNewType);
}

void Bindto::ShowNewTypeDlg(BindtoNewType& addNewType)
{
    while (true)
    {
        if (addNewType.ShowModal() == wxID_OK)
        {
            wxString ft = addNewType.GetFortranType();
            wxString bt = addNewType.GetBindCType().Trim(true).Trim(false);
            wxString ct = addNewType.GetCType().Trim(true).Trim(false);
            PrepateTypes(ft,bt,ct);

            if (m_TypeMap.count(ft) == 0)
            {
                wxArrayString bcta;
                bcta.Add(bt);
                bcta.Add(ct);
                m_TypeMap[ft] = bcta;
                m_IsTypeMapDefault = false;
                FillTypeList();
                break;
            }
            else
            {
                wxString mstr = _T("Binding for \"") + ft + _T("\" already defined!");
                cbMessageBox(mstr, _("Error"), wxICON_ERROR);
            }
        }
        else
            break;
    }
}

void Bindto::PrepateTypes(wxString& ft, wxString& bt, wxString& ct)
{
    bt.Trim(true).Trim(false);
    ct.Trim(true).Trim(false);
    ft.Replace(_T(" "),_T(""));
    if (ft.StartsWith(_T("character(")))
    {
        int idx = ft.Find(_T("kind="));
        if (idx != wxNOT_FOUND)
        {
            wxString kn = ft.Mid(idx+5);
            int idx1 = kn.Find(',');
            int idx2 = kn.Find(')');
            if (idx1 != wxNOT_FOUND && idx2 != wxNOT_FOUND)
            {
                if (idx1 > idx2)
                    kn.Truncate(idx2);
                else
                    kn.Truncate(idx1);
            }
            else if (idx1 != wxNOT_FOUND)
                kn.Truncate(idx1);
            else if (idx2 != wxNOT_FOUND)
                kn.Truncate(idx2);
            ft = _T("character(kind=") + kn + _T(")");
        }
        else
            ft = _T("character");
    }
    else if (ft.StartsWith(_T("character")))
        ft = _T("character");
    else if (ft.StartsWith(_T("integer(")) ||
             ft.StartsWith(_T("real(")) ||
             ft.StartsWith(_T("complex(")))
    {
        ft.Replace(_T("kind="),_T(""));
    }
    else if (ft.StartsWith(_T("integer*")) ||
             ft.StartsWith(_T("real*")))
    {
        ft.Replace(_T("*"),_T("("),false);
        ft.Append(_T(")"));
    }
}

void Bindto::OnEdit(wxCommandEvent& event)
{
    long sel = lv_Types->GetFirstSelected();
    if (sel == -1)
        return;
    wxString ft_old = lv_Types->GetItemText(sel);
    wxArrayString bcArr = m_TypeMap[ft_old];
    wxString bt_old = bcArr[0];
    wxString ct_old = bcArr[1];

    BindtoNewType editNewType(this);
    editNewType.SetEditType(ft_old,bt_old,ct_old);
    while (true)
    {
        if (editNewType.ShowModal() == wxID_OK)
        {
            wxString ft = editNewType.GetFortranType();
            wxString bt = editNewType.GetBindCType().Trim(true).Trim(false);
            wxString ct = editNewType.GetCType().Trim(true).Trim(false);
            PrepateTypes(ft,bt,ct);
            if (ft.IsSameAs(ft_old) && bt.IsSameAs(bt_old) && ct.IsSameAs(ct_old))
                break;
            else
            {
                // type was changed
                m_TypeMap.erase(ft_old);
                wxArrayString bcta;
                bcta.Add(bt);
                bcta.Add(ct);
                m_TypeMap[ft] = bcta;
                m_IsTypeMapDefault = false;
                FillTypeList();
                break;
            }
        }
        else
            break;
    }
}

void Bindto::OnRemove(wxCommandEvent& event)
{
    long sel = lv_Types->GetFirstSelected();
    if (sel == -1)
        return;
    m_TypeMap.erase(lv_Types->GetItemText(sel));
    m_IsTypeMapDefault = false;
    FillTypeList();
}

void Bindto::OnDefaults(wxCommandEvent& event)
{
    FillTypeMapDefault();
    FillTypeList();
}

wxString Bindto::SplitLines(const wxString& txt, Language lang)
{
    size_t llen;
    wxString csym;
    wxString comment;
    if (lang == Fortran)
    {
        llen = 132 - 2;
        csym = _T(" &");
        comment = _T("!");
    }
    else if (lang == C)
    {
        llen = 100;
        csym = _T("");
        comment = _T("//");
    }
    else if (lang == Python)
    {
        llen = 100;
        csym = _T(" \\");
        comment = _T("#");
    }
    else
        return _T("Programming error. This should not happen.");

    wxArrayString txtArrShort;
    wxArrayString txtArr;
    wxStringTokenizer tkz(txt, _T("\n"), wxTOKEN_RET_EMPTY_ALL);
    while ( tkz.HasMoreTokens() )
        txtArr.Add(tkz.GetNextToken());

    for (size_t i=0; i<txtArr.size(); i++)
    {
        wxString codeStr;
        wxString comStr;
        int idxcom = txtArr[i].Find(comment);
        if (idxcom == wxNOT_FOUND)
            codeStr = txtArr[i].Trim();
        else
        {
            codeStr = txtArr[i].Mid(0,idxcom).Trim();
            comStr = txtArr[i].Mid(idxcom+comment.size());
        }
        wxString noSpaceCodeStr = codeStr;
        noSpaceCodeStr.Trim(false);
        size_t nSpace = codeStr.length() - noSpaceCodeStr.length();
        if (nSpace > llen/3)
            nSpace = llen/3;
        while (true)
        {
            bool isShortStr = true;
            if (codeStr.length() > llen)
            {
                isShortStr = false;
                wxString leftStr = codeStr.Mid(0,llen);
                wxString rightStr = codeStr.Mid(llen);
                int idx1 = leftStr.Find(',', true);
                int idx2 = leftStr.Find(' ', true);
                int idx3 = leftStr.Find('=', true);
                int idx = std::max(idx1,idx2);
                idx = std::max(idx,idx3);
                if (idx == wxNOT_FOUND)
                    isShortStr = true;
                else
                {
                    txtArrShort.Add(leftStr.Mid(0,idx+1) + csym);
                    wxString spaces;
                    codeStr = spaces.Append(' ',nSpace+4) + leftStr.Mid(idx+1) + rightStr;
                }
            }

            if (isShortStr)
            {
                wxString shortStr = codeStr;

                if (shortStr.find_first_not_of(_T(" \n")) != wxString::npos && !comStr.IsEmpty())
                    shortStr.Append(_T(" ") + comment + comStr);
                else if (!comStr.IsEmpty())
                    shortStr.Append(comment + comStr);
                txtArrShort.Add(shortStr);
                break;
            }
        }
    }
    wxString txtAll;
    for (size_t i=0; i<txtArrShort.size(); i++)
    {
        txtAll.Append(txtArrShort[i] + _T("\n"));
    }
    return txtAll;
}

void Bindto::GetSubStrFtoC(wxArrayString &strFtoC)
{
    wxString tab;
    tab << GetIS(1);
    strFtoC.Add(_T("subroutine string_copy_f_c(f_string, c_string)"));
    strFtoC.Add(tab + _T("character(len=*), intent(in) :: f_string"));
    strFtoC.Add(tab + _T("character(len=1,kind=c_char), dimension(*), intent(out) :: c_string(*)"));
    strFtoC.Add(tab + _T("integer :: i, chlen\n"));
    strFtoC.Add(tab + _T("chlen = len(f_string)"));
    strFtoC.Add(tab + _T("do i = 1, chlen"));
    strFtoC.Add(tab + tab + _T("c_string(i) = f_string(i:i)"));
    strFtoC.Add(tab + _T("end do"));
    strFtoC.Add(tab + _T("c_string(chlen+1) = c_null_char"));
    strFtoC.Add(_T("end subroutine"));
}

void Bindto::GetSubStrCtoF(wxArrayString &strCtoF)
{
    wxString tab;
    tab << GetIS(1);
    strCtoF.Add(_T("subroutine string_copy_c_f(c_string, f_string)"));
    strCtoF.Add(tab + _T("character(len=1,kind=c_char), dimension(*), intent(in) :: c_string"));
    strCtoF.Add(tab + _T("character(len=*), intent(out) :: f_string"));
    strCtoF.Add(tab + _T("integer :: i, chlen\n"));
    strCtoF.Add(tab + _T("i = 1"));
    strCtoF.Add(tab + _T("chlen = len(f_string)"));
    strCtoF.Add(tab + _T("do while(c_string(i)/=c_null_char .and. i<=chlen)"));
    strCtoF.Add(tab + tab + _T("f_string(i:i) = c_string(i)"));
    strCtoF.Add(tab + tab + _T("i = i + 1"));
    strCtoF.Add(tab + _T("end do"));
    strCtoF.Add(tab + _T("if (i<=chlen) f_string(i:) = ' '"));
    strCtoF.Add(_T("end subroutine"));
}

void Bindto::GetFunStrLen(wxArrayString &strLen)
{
    wxString tab;
    tab << GetIS(1);
    strLen.Add(_T("function string_len(cstr)"));
    strLen.Add(tab + _T("integer :: string_len"));
    strLen.Add(tab + _T("character(kind=c_char,len=1), dimension(*) :: cstr\n"));
    strLen.Add(tab + _T("string_len = 1"));
    strLen.Add(tab + _T("do while(cstr(string_len) /= c_null_char)"));
    strLen.Add(tab + tab + _T("string_len = string_len + 1"));
    strLen.Add(tab + _T("end do"));
    strLen.Add(tab + _T("string_len = string_len - 1"));
    strLen.Add(_T("end function"));
}

void Bindto::GetFunIntToLog(wxArrayString &strArr)
{
    wxString tab;
    tab << GetIS(1);
    strArr.Add(_T("elemental function int_to_log(int_val)"));
    strArr.Add(tab + _T("integer(c_int), intent(in) :: int_val"));
    strArr.Add(tab + _T("logical :: int_to_log\n"));
    strArr.Add(tab + _T("if (int_val == 0) then"));
    strArr.Add(tab + tab + _T("int_to_log = .false."));
    strArr.Add(tab + _T("else"));
    strArr.Add(tab + tab + _T("int_to_log = .true."));
    strArr.Add(tab + _T("end if"));
    strArr.Add(_T("end function"));
}

void Bindto::GetFunLogToInt(wxArrayString &strArr)
{
    wxString tab;
    tab << GetIS(1);
    strArr.Add(_T("elemental function log_to_int(log_val)"));
    strArr.Add(tab + _T("logical, intent(in) :: log_val"));
    strArr.Add(tab + _T("integer(c_int) :: log_to_int\n"));
    strArr.Add(tab + _T("if (log_val) then"));
    strArr.Add(tab + tab + _T("log_to_int = 1"));
    strArr.Add(tab + _T("else"));
    strArr.Add(tab + tab + _T("log_to_int = 0"));
    strArr.Add(tab + _T("end if"));
    strArr.Add(_T("end function"));
}

wxString Bindto::GetHelperModule(bool useGlobal)
{
    wxString help;
    if (!useGlobal && !m_WriteStrCtoF && !m_WriteStrFtoC && !m_WriteStrLen &&
        !m_WriteLogToInt && !m_WriteIntToLog)
        return wxEmptyString;

    if (useGlobal && !m_GlobWriteStrCtoF && !m_GlobWriteStrFtoC && !m_GlobWriteStrLen &&
        !m_GlobWriteLogToInt && !m_GlobWriteIntToLog)
        return wxEmptyString;

    wxString tab;
    tab << GetIS(1);
    help << _T("module bindc_helper_bc\n");
    help << tab << _T("use, intrinsic :: iso_c_binding\n");
    help << tab << _T("implicit none\n");
    help << _T("contains\n");
    if ((!useGlobal && m_WriteStrLen) || (useGlobal && m_GlobWriteStrLen))
    {
        help << _T("\n");
        wxArrayString strLen;
        GetFunStrLen(strLen);
        for (size_t i=0;i<strLen.size();i++)
            help << tab << strLen.Item(i) << _T("\n");
    }
    if ((!useGlobal && m_WriteStrCtoF) || (useGlobal && m_GlobWriteStrCtoF))
    {
        help << _T("\n");
        wxArrayString strCtoF;
        GetSubStrCtoF(strCtoF);
        for (size_t i=0;i<strCtoF.size();i++)
            help << tab << strCtoF.Item(i) << _T("\n");
    }
    if ((!useGlobal && m_WriteStrFtoC) || (useGlobal && m_GlobWriteStrFtoC))
    {
        help << _T("\n");
        wxArrayString strFtoC;
        GetSubStrFtoC(strFtoC);
        for (size_t i=0;i<strFtoC.size();i++)
            help << tab << strFtoC.Item(i) << _T("\n");
    }
    if ((!useGlobal && m_WriteLogToInt) || (useGlobal && m_GlobWriteLogToInt))
    {
        help << _T("\n");
        wxArrayString strArr;
        GetFunLogToInt(strArr);
        for (size_t i=0;i<strArr.size();i++)
            help << tab << strArr.Item(i) << _T("\n");
    }
    if ((!useGlobal && m_WriteIntToLog) || (useGlobal && m_GlobWriteIntToLog))
    {
        help << _T("\n");
        wxArrayString strArr;
        GetFunIntToLog(strArr);
        for (size_t i=0;i<strArr.size();i++)
            help << tab << strArr.Item(i) << _T("\n");
    }
    help << _T("end module\n");
    return help;
}

void Bindto::PrepareAssumedShapeVariables(wxString& txtBindSecond, const wxArrayString& argArr, const wxArrayString& dimVarNames,
                                          wxArrayString& additionalDeclar, wxArrayString& addVarNames, wxArrayString& addVarNamesC,
                                          const wxArrayString& varNamesOfDim, const StrSet& argHideSetPy,
                                          wxArrayString& additionalDeclarPy, wxArrayString& addVarNamesPy, wxArrayString& addArgNamesPy)
{
    if (dimVarNames.size() == 0)
        return;

    if (dimVarNames.size() != varNamesOfDim.size())
        return; // programming error

    wxArrayInt ndims;
    wxString varNameOld;
    int iShape = 0;
    for (size_t i=0; i<varNamesOfDim.size(); i++)
    {
        if (varNameOld.IsSameAs(varNamesOfDim.Item(i)))
            iShape += 1;
        else if (i > 0)
        {
            int nd = iShape + 1;
            for (int j=0; j<nd; j++)
                ndims.Add(nd);
            iShape = 0;
        }
        varNameOld = varNamesOfDim.Item(i);
    }
    int nd = iShape + 1;
    for (int j=0; j<nd; j++)
        ndims.Add(nd);
    if (ndims.size() != dimVarNames.size())
    {
        Manager::Get()->GetLogManager()->DebugLog(_T("FortranProject: ndims.size() != dimVarNames.size()"));
        return; // programming error;
    }

    varNameOld = _T("");
    for (size_t i=0; i<dimVarNames.size(); i++)
    {
        if (varNameOld.IsSameAs(varNamesOfDim.Item(i)))
            iShape += 1;
        else
            iShape = 0;
        varNameOld = varNamesOfDim.Item(i);

        wxString var = dimVarNames.Item(i);
        txtBindSecond.Replace(DIM_VAR_KEY, var, false);
        if (argArr.Index(var) == wxNOT_FOUND && addVarNames.Index(var) == wxNOT_FOUND)
        {
            additionalDeclar.Add(_T("integer(c_int), intent(in) :: ") + var);
            addVarNames.Add(var);
            addVarNamesC.Add(_T("int* ") + var);
            if (argHideSetPy.count(varNamesOfDim.Item(i)) == 1)
            {
                wxString dimVarKeyI = DIM_VAR_KEY + wxString::Format(_T("%d"),iShape);
                for (size_t j=0; j<additionalDeclarPy.size(); j++)
                {
                    if (additionalDeclarPy.Item(j).Replace(dimVarKeyI, var, false) > 0)
                        break;
                }
                addArgNamesPy.Add(_T("int ") + var);
            }
            else
            {
                int iShapeWrite = ndims[i] - iShape - 1;
                wxString sShape = wxString::Format(_T("%d"),iShapeWrite);
                additionalDeclarPy.Add(_T("cdef int ") + var + _T(" = ") + varNamesOfDim.Item(i) + _T(".shape[") + sShape + _T("]"));
            }
            addVarNamesPy.Add(_T("&") + var);
        }
    }
}

void Bindto::AddDimVariables(const wxArrayString& argArr, wxArrayString& dimVarNames, int nDimVarAdd, wxString varFirstPart,
                             const wxString& argName, wxArrayString& varNamesOfDim)
{
    wxString n1 = varFirstPart + _T("%i");
    wxString vname;
    int i=0;
    for (int nd=0; nd<nDimVarAdd; nd++)
    {
        while (vname.IsEmpty())
        {
            i++;
            wxString vn1 = wxString::Format(n1,i);
            if (argArr.Index(vn1) == wxNOT_FOUND && dimVarNames.Index(vn1) == wxNOT_FOUND)
                vname = vn1;
        }
        dimVarNames.Add(vname);
        vname = wxEmptyString;
        varNamesOfDim.Add(argName);
    }
}

void Bindto::HideAssumedShape(const wxString& vdim, wxString& vdimHid, int& nAssumedDim)
{
    vdimHid = vdim;
    nAssumedDim = vdimHid.Replace(_T(":"), DIM_VAR_KEY);
}

void Bindto::AddDimVariablesFromDoc(wxArrayString& dimVarNames, int& nDimVarAdd,  const wxString& docString,
                                    const wxString& argName, wxArrayString& varNamesOfDim)
{
    // Get dimensions of allocatable array from doc string e.g. dimension(m,n)
    if (nDimVarAdd == 0)
        return;
    wxString dimsStr;
    wxString lwDocString = docString.Lower().Trim(true);
    wxRegEx reDim1(_T("^dimension[ \\t]*\\(([[:alnum:]_, ]+)"));
    wxRegEx reDim2(_T("[ \\t!><]+dimension[ \\t]*\\(([[:alnum:]_, ]+)"));
    if (reDim1.Matches(lwDocString))
    {
        dimsStr = reDim1.GetMatch(lwDocString,1);
    }
    if (dimsStr.IsEmpty() && reDim2.Matches(lwDocString))
    {
        dimsStr = reDim2.GetMatch(lwDocString,1);
    }
    if (dimsStr.IsEmpty())
        return;

    wxArrayString dimArr;
    wxStringTokenizer tkz(dimsStr, _T("(), "), wxTOKEN_STRTOK );
    while ( tkz.HasMoreTokens() )
        dimArr.Add(tkz.GetNextToken());
    if (int(dimArr.size()) != nDimVarAdd)
        return; // wrong number of variables

    for (size_t i=0; i<dimArr.size(); i++)
    {
        dimVarNames.Add(dimArr.Item(i));
        varNamesOfDim.Add(argName);
    }
    nDimVarAdd = 0;
}

wxString Bindto::GetCName(const wxString& procName, const wxString& moduleName)
{
    if (m_BindCName.IsEmpty())
        return procName;
    return GetProcName(procName, moduleName, m_BindCName);
}

wxString Bindto::GetProcName(const wxString& procName, const wxString& moduleName, const wxString& nameFrame)
{
    wxString cName = nameFrame;
    wxString cName_lw = cName.Lower();
    wxString keyProc = PROCNAME_KEY;
    wxString keyModule = MODULENAME_KEY;
    wxString keyMod = MODNAME_KEY;
    int idx = cName_lw.Find(keyProc);
    if (idx != wxNOT_FOUND)
    {
        cName = cName.Mid(0,idx) + procName + cName.Mid(idx+keyProc.Len());
        cName_lw = cName.Lower();
    }
    idx = cName_lw.Find(keyModule);
    if (idx != wxNOT_FOUND)
    {
        cName = cName.Mid(0,idx) + moduleName + cName.Mid(idx+keyModule.Len());
        cName_lw = cName.Lower();
    }
    idx = cName_lw.Find(keyMod);
    if (idx != wxNOT_FOUND)
    {
        wxString modName = moduleName;
        modName.Replace(_T("_"),_T(""));
        if (modName.Len() > 3)
            modName = modName.Mid(0,3);
        cName = cName.Mid(0,idx) + modName + cName.Mid(idx+keyMod.Len());
    }
    return cName;
}

void Bindto::AddDestructors(wxString& txtBind, wxString& txtHeadersMod, wxString& txtCythonDtor, wxString& txtCythonFirst, const wxString& moduleName)
{
    if (m_DefinedTypes.size() == 0)
        return;

    wxString txtDest;
    wxString txtDestH;
    for ( StrSet::iterator it=m_DefinedTypes.begin(); it != m_DefinedTypes.end(); ++it)
    {
        wxString type = *it;
        if (m_Deallocators.count(type) == 1)
            continue;
        wxString destName = type + _T("_dtor");
        wxString cDestName = GetCName(destName, moduleName);
        txtDest << GetIS() << _T("subroutine ") << destName << _T("_bc") << _T("(this_cp) bind(c,name='") << cDestName << _T("')\n");
        m_Indent++;
        txtDest << GetIS() << _T("type(c_ptr), intent(in) :: this_cp\n");
        txtDest << GetIS() << _T("type(") << type << _T("), pointer :: this_fp\n\n");
        txtDest << GetIS() << _T("call c_f_pointer(this_cp, this_fp)\n");
        txtDest << GetIS() << _T("deallocate(this_fp)\n");
        m_Indent--;
        txtDest << GetIS() << _T("end subroutine\n\n");

        txtDestH << _T("void ") << cDestName << _T("(void** this_cp);\n");
    }
    txtBind << txtDest;
    txtHeadersMod << txtDestH;

    wxString txtDestPy;
    wxString txtDestPyH;
    wxString txtDelPy;
    for ( StrSet::iterator it=m_DefinedTypes.begin(); it != m_DefinedTypes.end(); ++it)
    {
        wxString type = *it;
        if (m_Deallocators.count(type) == 1)
        {
            wxString procName = m_Deallocators[type];
            txtDestPy << GetIS(2) << procName << _T("(&self._") << type << _T("_cp)\n");
            txtDelPy << _T("\n") << GetIS(1) << _T("cdef ")<< type << _T("_cp") << _T("_del_py(self):\n");
            txtDelPy << GetIS(2) << procName << _T("(&self._") << type << _T("_cp)\n");
        }
        else
        {
            wxString destName = type + _T("_dtor");
            wxString cDestName = GetCName(destName, moduleName);
            txtDestPy << GetIS(2) << cDestName << _T("(&self._") << type << _T("_cp)\n");
            txtDestPyH << GetIS(1) << _T("void ") << cDestName << _T("(void** this_cp)\n");
            txtDelPy << _T("\n") << GetIS(1) << _T("cdef ")<< type << _T("_cp") << _T("_del_py(self):\n");
            txtDelPy << GetIS(2) << cDestName << _T("(&self._") << type << _T("_cp)\n");
        }
    }
    if (!txtDestPy.IsEmpty())
    {
        txtCythonDtor << _T("\n") << GetIS(1) << _T("def __dealloc__(self):\n");
        txtCythonDtor << txtDestPy;
    }
    txtCythonFirst << txtDestPyH;
    txtCythonDtor << txtDelPy;

}

void Bindto::AddConstructors(wxString& txtBind, wxString& txtHeadersMod, wxString& txtCythonCtor, wxString& txtCythonFirst, const wxString& moduleName)
{

    if (m_DefinedTypes.size() == 0)
        return;

    StrSet noArgAllocatedTypes;
    for ( StrSet::iterator it=m_NoArgConstructors.begin(); it != m_NoArgConstructors.end(); ++it)
    {
        wxString type = *it;
        int idx = type.Find(_T("("));
        if (idx != wxNOT_FOUND)
        {
            type = GetToken(type, idx);
        }
        if (type.size() <= 2)
            continue;

        type = type.Mid(1,type.size()-2).Trim(true).Trim(false);
        noArgAllocatedTypes.insert(type);
    }

    wxString txtCon;
    wxString txtConH;
    wxString txtConPy;
    wxString txtConPyH;
    for ( StrSet::iterator it=m_DefinedTypes.begin(); it != m_DefinedTypes.end(); ++it)
    {
        wxString type = *it;
        if (noArgAllocatedTypes.count(type) == 1)
            continue;

        wxString conName = GetConstructorName(type);
        wxString cConName = GetCName(conName, moduleName);
        wxString fConName = conName + _T("_bc");
        txtCon << GetIS() << _T("function ") << fConName << _T("() bind(c,name='") << cConName << _T("')\n");
        m_Indent++;
        txtCon << GetIS() << _T("type(c_ptr) :: ") << fConName << _T("\n");
        txtCon << GetIS() << _T("type(") << type << _T("), pointer :: this_fp\n\n");
        txtCon << GetIS() << _T("allocate(this_fp)\n");
        txtCon << GetIS() << fConName << _T(" = c_loc(this_fp)\n");
        m_Indent--;
        txtCon << GetIS() << _T("end function\n\n");

        wxString cHeader = _T("void* ") + cConName + _T("()");
        txtConH << cHeader << _T(";\n");
        m_NoArgConstructors.insert(_T("type(")+type+_T(")"));

        txtConPy << GetIS(2) << _T("self._") << type << _T("_cp = ") << cConName << _T("()\n");
        txtConPyH << GetIS(1) << cHeader << _T("\n");
    }
    txtBind << txtCon;
    txtHeadersMod << txtConH;
    if (!txtConPy.IsEmpty())
    {
        if (!m_HasPyClassConstructor)
        {
            txtCythonCtor << _T("\n") << GetIS(1) << _T("def __cinit__(self):\n");
            txtCythonCtor << txtConPy;
        }
        txtCythonFirst << txtConPyH;
    }
}

wxString Bindto::GetConstructorName(const wxString& type)
{
    wxString conName = type + _T("_ctor");
    if (m_ModuleChildNames.count(conName) == 1)
    {
        for (int i=2; i<100; i++)
        {
            conName = wxString::Format(type + _T("%d_ctor"), i);
            if (m_ModuleChildNames.count(conName) == 0)
                break;
        }
    }
    return conName;
}

bool Bindto::IsConstructor(TokenF* token)
{
    if ((token->m_TokenKind == tkSubroutine || token->m_TokenKind == tkFunction) &&
        ((!m_CtorStartsWith.IsEmpty() && token->m_Name.StartsWith(m_CtorStartsWith)) ||
        (!m_CtorEndsWith.IsEmpty() && token->m_Name.EndsWith(m_CtorEndsWith))) )
        return true;
    return false;
}

bool Bindto::IsDestructor(TokenF* token)
{
    if ((!m_DtorStartsWith.IsEmpty() && token->m_Name.StartsWith(m_DtorStartsWith)) ||
        (!m_DtorEndsWith.IsEmpty() && token->m_Name.EndsWith(m_DtorEndsWith)) )
        return true;
    return false;
}

void Bindto::OnClick_cbCtorStart(wxCommandEvent& event)
{
    if (cb_ctorStart->IsChecked())
        tc_ctorStart->Enable(true);
    else
    {
        if (tc_ctorStart->GetValue().Trim().IsEmpty())
            tc_ctorStart->SetValue(_T("ctor_"));
        tc_ctorStart->Enable(false);
    }
}

void Bindto::OnClick_cbCtorEnd(wxCommandEvent& event)
{
    if (cb_ctorEnd->IsChecked())
        tc_ctorEnd->Enable(true);
    else
    {
        if (tc_ctorEnd->GetValue().Trim().IsEmpty())
            tc_ctorEnd->SetValue(_T("_ctor"));
        tc_ctorEnd->Enable(false);
    }
}

void Bindto::OnClick_cbDtorStart(wxCommandEvent& event)
{
    if (cb_dtorStart->IsChecked())
        tc_dtorStart->Enable(true);
    else
    {
        if (tc_dtorStart->GetValue().Trim().IsEmpty())
            tc_dtorStart->SetValue(_T("dtor_"));
        tc_dtorStart->Enable(false);
    }
}

void Bindto::OnClick_cbDtorEnd(wxCommandEvent& event)
{
    if (cb_dtorEnd->IsChecked())
        tc_dtorEnd->Enable(true);
    else
    {
        if (tc_dtorEnd->GetValue().Trim().IsEmpty())
            tc_dtorEnd->SetValue(_T("_dtor"));
        tc_dtorEnd->Enable(false);
    }
}

void Bindto::Onrb_ActiveProjectSelect(wxCommandEvent& event)
{
    bool enab = false;
    if (rb_ActiveProject->GetValue())
        enab = true;

    cb_globalToOne->Enable(enab);
    tc_globalFilename->Enable(enab);
    st_globalFilename->Enable(enab);

    wxString initstr;
    if (rb_ActiveProject->GetValue())
        initstr = m_InitialOutputDirFile;
    else
        initstr = m_InitialOutputDirProj;
    wxString dir = tc_OutputDir->GetValue();
    if (dir.IsSameAs(initstr))
    {
        if (rb_ActiveProject->GetValue())
            tc_OutputDir->SetValue(m_InitialOutputDirProj);
        else
            tc_OutputDir->SetValue(m_InitialOutputDirFile);
    }
}

wxString Bindto::GetPyName(const wxString& procName, const wxString& moduleName)
{
    if (m_PyFuncName.IsEmpty())
        return procName + _T("_f");
    return GetProcName(procName, moduleName, m_PyFuncName);
}

Bindto::TypePyx Bindto::GetBindTypePy(const TypeBind& tya)
{
    TypePyx tyaPy;
    tyaPy.hide = false;
    wxString fTName;
    wxString decPyx;
    if (tya.cType.EndsWith(_T("*")))
        decPyx = tya.cType.Mid(0,tya.cType.size()-1);
    if (decPyx.IsSameAs(_T("void*")) || decPyx.IsSameAs(_T("void")))
    {
        if (tya.fType.StartsWith(_T("type(")))
            fTName = GetToken(tya.fType,4);
        else if (tya.fType.StartsWith(_T("class(")))
            fTName = GetToken(tya.fType,5);
        if (fTName.StartsWith(_T("(")) && fTName.EndsWith(_T(")")))
            fTName = fTName.Mid(1,fTName.size()-2);
        decPyx = _T("");
    }

    int idx = tya.bType.Find(_T("intent("));
    if (idx != wxNOT_FOUND)
    {
        idx = tya.bType.Find(_T("intent(out)"));
        if (idx != wxNOT_FOUND)
        {
            tyaPy.intent = _T("out");
            tyaPy.hide = true;
        }
        idx = tya.bType.Find(_T("intent(inout)"));
        if (idx != wxNOT_FOUND)
            tyaPy.intent = _T("inout");
    }

    idx = tya.bType.Find(_T("dimension("));
    size_t ndim = 0;
    if (idx != wxNOT_FOUND)
    {
        wxString dims = GetToken(tya.bType,idx+9);
        if (tyaPy.intent.IsSameAs(_T("out")) && dims.Find(_T("*")) == wxNOT_FOUND)
        {
            wxArrayString dimsArr;
            wxStringTokenizer tkz(dims, _T("(), "),wxTOKEN_STRTOK);
            while ( tkz.HasMoreTokens() )
            {
                wxString d1str = tkz.GetNextToken();
                if (d1str.IsSameAs(DIM_VAR_KEY))
                    d1str << wxString::Format(_T("%d"),dimsArr.size());
                dimsArr.Insert(d1str,0);
            }

            ndim = dimsArr.size();
            dims = _T("[");
            for (size_t i=0; i<ndim; i++)
                dims << dimsArr.Item(i) << _T(",");
            dims.Truncate(dims.size()-1);
            dims << _T("]");

            wxString npType;
            if (m_C2NumpyTypes.count(decPyx) == 1)
                npType = _T("np.") + m_C2NumpyTypes[decPyx];
            else
                npType = decPyx;
            tyaPy.initStr = _T(" = np.empty(") + dims + _T(", dtype=") + npType + _T(")");
            decPyx = wxString::Format(_T("np.ndarray[") + decPyx + _T(",ndim=%d]"), ndim);
        }
        else
        {
            ndim = dims.Replace(_T(","),_T(";")) + 1;
            decPyx = wxString::Format(_T("np.ndarray[") + decPyx + _T(",ndim=%d]"), ndim);
            tyaPy.hide = false;
        }
    }
    tyaPy.declarPyxFirst = decPyx;
    if (ndim > 0)
    {
        tyaPy.callCSecond = _T("[");
        for (size_t i=0; i<ndim; i++)
        {
            if (i+1 < ndim)
                tyaPy.callCSecond << _T("0,");
            else
                tyaPy.callCSecond << _T("0");
        }
        tyaPy.callCSecond << _T("]");
    }

    if (!fTName.IsEmpty())
        tyaPy.fDrvTypeName = fTName;

    return tyaPy;
}

wxString Bindto::CreateCythonFilename(const wxString& filename)
{
    wxFileName fname(filename);
    fname.SetPath(m_OutputDir);
    fname.SetExt(_T("pyx"));

    return CheckOverwriteFilename(fname);
}

void Bindto::GetInitialOutputDir(wxString& initialOutputDirFile, wxString& initialOutputDirProj)
{
    initialOutputDirFile = _T("");
    initialOutputDirProj = _T("");
    cbEditor* ed = Manager::Get()->GetEditorManager()->GetBuiltinActiveEditor();
    if (ed)
    {
        wxString fname = UnixFilename(ed->GetFilename());
        ProjectsArray* projects = Manager::Get()->GetProjectManager()->GetProjects();
        for (size_t i = 0; i < projects->GetCount(); ++i)
        {
            cbProject* pr = projects->Item(i);
            if (pr->GetFileByFilename(fname, false, true))
            {
                // file belongs to this project
                wxFileName dirname(pr->GetBasePath(),_T(""));
                dirname.AppendDir(_T("bind"));
                initialOutputDirFile = dirname.GetPath();
            }
        }
    }
    cbProject* pr = Manager::Get()->GetProjectManager()->GetActiveProject();
    if (pr)
    {
        wxFileName dirname(pr->GetBasePath(),_T(""));
        dirname.AppendDir(_T("bind"));
        initialOutputDirProj = dirname.GetPath();
    }
}

bool Bindto::MakeOutputDir()
{
    wxFileName dirname = wxFileName::DirName(m_OutputDir);
    if (!dirname.DirExists() && !dirname.Mkdir())
        return false;
    return true;
}

bool Bindto::VlidatePyFuncName()
{
    wxString msg;
    if (m_PyFuncName.IsEmpty())
        msg = _("\"Python function names\" text field cannot be empty.");
    else if (m_PyFuncName.IsSameAs(m_BindCName))
        msg = _("Python function names should be different from Bind(C) names.\nCorrect \"BIND(C, name=#)\" or \"Python function names\" text field.");

    if (!msg.IsEmpty())
    {
        cbMessageBox( msg, _("Error"), wxICON_ERROR);
        return false;
    }
    return true;
}

void Bindto::Onbt_OutputDirClick(wxCommandEvent& event)
{
    wxDirDialog dlg(this, _T("Choose output directory"), tc_OutputDir->GetValue(), wxDD_DEFAULT_STYLE | wxDD_NEW_DIR_BUTTON);
    if (dlg.ShowModal() == wxID_OK)
    {
         wxString path = dlg.GetPath();
         tc_OutputDir->SetValue(path);
    }
}

void Bindto::Oncb_genCythonClick(wxCommandEvent& event)
{
    bool enpy = cb_genCython->GetValue();
    pn_pyOpts->Enable(enpy);
}

void Bindto::OnCopy(wxCommandEvent& event)
{
    long sel = lv_Types->GetFirstSelected();
    if (sel == -1)
        return;
    wxString ft_old = lv_Types->GetItemText(sel);
    wxArrayString bcArr = m_TypeMap[ft_old];
    wxString bt_old = bcArr[0];
    wxString ct_old = bcArr[1];

    BindtoNewType newTypeDlg(this);
    newTypeDlg.SetEditType(ft_old,bt_old,ct_old);
    ShowNewTypeDlg(newTypeDlg);
}
