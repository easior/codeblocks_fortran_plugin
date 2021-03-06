/*
 * This file is part of the Code::Blocks IDE and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include <sdk.h>
#include "fpoptionsdlg.h"
#include "fortranproject.h"
#include <wx/intl.h>
#include <wx/listbox.h>
#include <wx/xrc/xmlres.h>
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/combobox.h>
#include <wx/treectrl.h>
#include <wx/slider.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/regex.h>
#include <configmanager.h>
#include <manager.h>
#include <globals.h>


BEGIN_EVENT_TABLE(FPOptionsDlg, wxPanel)
    EVT_UPDATE_UI(-1, FPOptionsDlg::OnUpdateUI)
END_EVENT_TABLE()

FPOptionsDlg::FPOptionsDlg(wxWindow* parent, NativeParserF* np, FortranProject* fp)
    : m_pNativeParser(np),
    m_pFortranProject(fp)
{
    ConfigManager* cfg = Manager::Get()->GetConfigManager(_T("fortran_project"));

    wxXmlResource::Get()->LoadPanel(this, parent, _T("dlgFPSettings"));

    XRCCTRL(*this, "chkNoCC", wxCheckBox)->SetValue(!cfg->ReadBool(_T("/use_code_completion"), true));
    XRCCTRL(*this, "chkSmartCodeCompletion", wxCheckBox)->SetValue(cfg->ReadBool(_T("/use_smart_code_completion"), true));
    XRCCTRL(*this, "chkOnlyUseAssociated", wxCheckBox)->SetValue(cfg->ReadBool(_T("/only_use_associated"), true));
    XRCCTRL(*this, "chkShowHiddenEntities", wxCheckBox)->SetValue(cfg->ReadBool(_T("/show_hidden_entities"), false));
    XRCCTRL(*this, "chkShowTypeVariables", wxCheckBox)->SetValue(cfg->ReadBool(_T("/show_type_variables"), true));
    XRCCTRL(*this, "spnMaxMatches", wxSpinCtrl)->SetValue(cfg->ReadInt(_T("/max_matches"), 16384));

    XRCCTRL(*this, "chkNoSB", wxCheckBox)->SetValue(!cfg->ReadBool(_T("/use_symbols_browser"), true));
    XRCCTRL(*this, "chkFloatSB", wxCheckBox)->SetValue(cfg->ReadBool(_T("/as_floating_window"), false));
    XRCCTRL(*this, "chkBottomTree", wxCheckBox)->SetValue(cfg->ReadBool(_T("/visible_bottom_tree"), true));
    XRCCTRL(*this, "chkSortSB", wxCheckBox)->SetValue(cfg->ReadBool(_T("/browser_sort_alphabetically"), true));
    XRCCTRL(*this, "chkLocVarSB", wxCheckBox)->SetValue(cfg->ReadBool(_T("/browser_show_local_variables"), false));
    XRCCTRL(*this, "chkInclSepar", wxCheckBox)->SetValue(cfg->ReadBool(_T("/browser_show_include_files_separately"), true));

    XRCCTRL(*this, "chkKL_1", wxCheckBox)->SetValue(cfg->ReadBool(_T("/lexer_keywords_set1"), true));
    XRCCTRL(*this, "chkKL_2", wxCheckBox)->SetValue(cfg->ReadBool(_T("/lexer_keywords_set2"), true));
    XRCCTRL(*this, "chkKL_3", wxCheckBox)->SetValue(cfg->ReadBool(_T("/lexer_keywords_set3"), false));
    XRCCTRL(*this, "chkKL_4", wxCheckBox)->SetValue(cfg->ReadBool(_T("/lexer_keywords_set4"), false));
    XRCCTRL(*this, "chkKL_5", wxCheckBox)->SetValue(cfg->ReadBool(_T("/lexer_keywords_set5"), false));
    XRCCTRL(*this, "chkKL_6", wxCheckBox)->SetValue(cfg->ReadBool(_T("/lexer_keywords_set6"), false));
    XRCCTRL(*this, "chkKL_7", wxCheckBox)->SetValue(cfg->ReadBool(_T("/lexer_keywords_set7"), false));
    XRCCTRL(*this, "chkKL_8", wxCheckBox)->SetValue(cfg->ReadBool(_T("/lexer_keywords_set8"), false));
    XRCCTRL(*this, "chkKL_9", wxCheckBox)->SetValue(cfg->ReadBool(_T("/lexer_keywords_set9"), false));

    XRCCTRL(*this, "rbCase", wxRadioBox)->SetSelection(cfg->ReadInt(_T("/keywords_case"), 0));

    XRCCTRL(*this, "chkCallTipsArrays", wxCheckBox)->SetValue(cfg->ReadBool(_T("/call_tip_arrays"), true));

    XRCCTRL(*this, "chkNoFortranInfo", wxCheckBox)->SetValue(!cfg->ReadBool(_T("/use_log_window"), true));
    XRCCTRL(*this, "chkComAbove", wxCheckBox)->SetValue(cfg->ReadBool(_T("/include_comments_above"), true));
    XRCCTRL(*this, "chkComBelow", wxCheckBox)->SetValue(cfg->ReadBool(_T("/include_comments_below"), true));
    XRCCTRL(*this, "chkDeclarLog", wxCheckBox)->SetValue(cfg->ReadBool(_T("/include_declarations_log"), true));
    XRCCTRL(*this, "chkLogComRight", wxCheckBox)->SetValue(cfg->ReadBool(_T("/include_log_comments_variable"), true));

    XRCCTRL(*this, "rbDocAlways", wxRadioButton)->SetValue(cfg->ReadBool(_T("/show_docs_always"), false));
    XRCCTRL(*this, "rbDocOnly", wxRadioButton)->SetValue(cfg->ReadBool(_T("/show_docs_only"), true));
    XRCCTRL(*this, "rbDocNot", wxRadioButton)->SetValue(cfg->ReadBool(_T("/show_docs_not"), false));
}

FPOptionsDlg::~FPOptionsDlg()
{
}

void FPOptionsDlg::OnUpdateUI(wxUpdateUIEvent& event)
{
    bool en = !XRCCTRL(*this, "chkNoCC", wxCheckBox)->GetValue();

    XRCCTRL(*this, "chkSmartCodeCompletion", wxCheckBox)->Enable(en);
    XRCCTRL(*this, "chkOnlyUseAssociated", wxCheckBox)->Enable(en);
    XRCCTRL(*this, "chkShowHiddenEntities", wxCheckBox)->Enable(en);
    XRCCTRL(*this, "spnMaxMatches", wxSpinCtrl)->Enable(en);
    XRCCTRL(*this, "rbCase", wxRadioBox)->Enable(en);
    XRCCTRL(*this, "chkKL_1", wxCheckBox)->Enable(en);
    XRCCTRL(*this, "chkKL_2", wxCheckBox)->Enable(en);
    XRCCTRL(*this, "chkKL_3", wxCheckBox)->Enable(en);
    XRCCTRL(*this, "chkKL_4", wxCheckBox)->Enable(en);
    XRCCTRL(*this, "chkKL_5", wxCheckBox)->Enable(en);
    XRCCTRL(*this, "chkKL_6", wxCheckBox)->Enable(en);
    XRCCTRL(*this, "chkKL_7", wxCheckBox)->Enable(en);
    XRCCTRL(*this, "chkKL_8", wxCheckBox)->Enable(en);
    XRCCTRL(*this, "chkKL_9", wxCheckBox)->Enable(en);

    en = !XRCCTRL(*this, "chkNoSB", wxCheckBox)->GetValue();
    XRCCTRL(*this, "chkFloatSB", wxCheckBox)->Enable(en);
    XRCCTRL(*this, "chkBottomTree", wxCheckBox)->Enable(en);
    XRCCTRL(*this, "chkSortSB", wxCheckBox)->Enable(en);

    en = !XRCCTRL(*this, "chkNoFortranInfo", wxCheckBox)->GetValue();
    XRCCTRL(*this, "chkComAbove", wxCheckBox)->Enable(en);
    XRCCTRL(*this, "chkComBelow", wxCheckBox)->Enable(en);
    XRCCTRL(*this, "chkDeclarLog", wxCheckBox)->Enable(en);
}

void FPOptionsDlg::OnApply()
{
    ConfigManager* cfg = Manager::Get()->GetConfigManager(_T("fortran_project"));

    // force parser to read its options that we write in the config
    cfg->Write(_T("/use_code_completion"), (bool)!XRCCTRL(*this, "chkNoCC", wxCheckBox)->GetValue());

    // set all other member options
    cfg->Write(_T("/use_smart_code_completion"), (bool)XRCCTRL(*this, "chkSmartCodeCompletion", wxCheckBox)->GetValue());
    cfg->Write(_T("/only_use_associated"), (bool)XRCCTRL(*this, "chkOnlyUseAssociated", wxCheckBox)->GetValue());
    cfg->Write(_T("/show_hidden_entities"), (bool)XRCCTRL(*this, "chkShowHiddenEntities", wxCheckBox)->GetValue());
    cfg->Write(_T("/show_type_variables"), (bool)XRCCTRL(*this, "chkShowTypeVariables", wxCheckBox)->GetValue());
    cfg->Write(_T("/max_matches"), (int)XRCCTRL(*this, "spnMaxMatches", wxSpinCtrl)->GetValue());

    cfg->Write(_T("/use_symbols_browser"), (bool)!XRCCTRL(*this, "chkNoSB", wxCheckBox)->GetValue());
    cfg->Write(_T("/as_floating_window"), (bool)XRCCTRL(*this, "chkFloatSB", wxCheckBox)->GetValue());
    cfg->Write(_T("/visible_bottom_tree"), (bool)XRCCTRL(*this, "chkBottomTree", wxCheckBox)->GetValue());
    cfg->Write(_T("/browser_sort_alphabetically"), (bool)XRCCTRL(*this, "chkSortSB", wxCheckBox)->GetValue());
    cfg->Write(_T("/browser_show_local_variables"), (bool)XRCCTRL(*this, "chkLocVarSB", wxCheckBox)->GetValue());
    cfg->Write(_T("/browser_show_include_files_separately"), (bool)XRCCTRL(*this, "chkInclSepar", wxCheckBox)->GetValue());

    cfg->Write(_T("/lexer_keywords_set1"), (bool)XRCCTRL(*this, "chkKL_1", wxCheckBox)->GetValue());
    cfg->Write(_T("/lexer_keywords_set2"), (bool)XRCCTRL(*this, "chkKL_2", wxCheckBox)->GetValue());
    cfg->Write(_T("/lexer_keywords_set3"), (bool)XRCCTRL(*this, "chkKL_3", wxCheckBox)->GetValue());
    cfg->Write(_T("/lexer_keywords_set4"), (bool)XRCCTRL(*this, "chkKL_4", wxCheckBox)->GetValue());
    cfg->Write(_T("/lexer_keywords_set5"), (bool)XRCCTRL(*this, "chkKL_5", wxCheckBox)->GetValue());
    cfg->Write(_T("/lexer_keywords_set6"), (bool)XRCCTRL(*this, "chkKL_6", wxCheckBox)->GetValue());
    cfg->Write(_T("/lexer_keywords_set7"), (bool)XRCCTRL(*this, "chkKL_7", wxCheckBox)->GetValue());
    cfg->Write(_T("/lexer_keywords_set8"), (bool)XRCCTRL(*this, "chkKL_8", wxCheckBox)->GetValue());
    cfg->Write(_T("/lexer_keywords_set9"), (bool)XRCCTRL(*this, "chkKL_9", wxCheckBox)->GetValue());

    cfg->Write(_T("/keywords_case"), (int)XRCCTRL(*this, "rbCase", wxRadioBox)->GetSelection());

    cfg->Write(_T("/call_tip_arrays"), (bool)XRCCTRL(*this, "chkCallTipsArrays", wxCheckBox)->GetValue());

    cfg->Write(_T("/use_log_window"), (bool)!XRCCTRL(*this, "chkNoFortranInfo", wxCheckBox)->GetValue());
    cfg->Write(_T("/include_comments_above"), (bool)XRCCTRL(*this, "chkComAbove", wxCheckBox)->GetValue());
    cfg->Write(_T("/include_comments_below"), (bool)XRCCTRL(*this, "chkComBelow", wxCheckBox)->GetValue());
    cfg->Write(_T("/include_declarations_log"), (bool)XRCCTRL(*this, "chkDeclarLog", wxCheckBox)->GetValue());
    cfg->Write(_T("/include_log_comments_variable"), (bool)XRCCTRL(*this, "chkLogComRight", wxCheckBox)->GetValue());

    cfg->Write(_T("/show_docs_always"), (bool)XRCCTRL(*this, "rbDocAlways", wxRadioButton)->GetValue());
    cfg->Write(_T("/show_docs_only"), (bool)XRCCTRL(*this, "rbDocOnly", wxRadioButton)->GetValue());
    cfg->Write(_T("/show_docs_not"), (bool)XRCCTRL(*this, "rbDocNot", wxRadioButton)->GetValue());

    m_pNativeParser->RereadOptions();
    m_pFortranProject->RereadOptions();
}
