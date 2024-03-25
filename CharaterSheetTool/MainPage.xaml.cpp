//
// MainPage.xaml.cpp
// Implémentation de la classe MainPage.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <sstream>

using namespace CharaterSheetTool;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

MainPage::MainPage()
{
	InitializeComponent();
}


void CharaterSheetTool::MainPage::rollButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	character->RandomizeAll();
	attackValue->Text = character->GetAttack().ToString();
	defenseValue->Text = character->GetDefense().ToString();
	luckValue->Text = character->GetLuck().ToString();
	goldAmount->Text = character->GetGold().ToString();
}


void CharaterSheetTool::MainPage::loadImageButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}


void CharaterSheetTool::MainPage::saveButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}

void CharaterSheetTool::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) // Attack button
{
	character->RandomizeAttack();
	attackValue->Text = character->GetAttack().ToString();
}


void CharaterSheetTool::MainPage::Button_Click_1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) // Defense button
{
	character->RandomizeDefense();
	defenseValue->Text = character->GetDefense().ToString();
}


void CharaterSheetTool::MainPage::Button_Click_2(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) // Luck button
{
	character->RandomizeLuck();
	luckValue->Text = character->GetLuck().ToString();
}


void CharaterSheetTool::MainPage::Button_Click_3(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) // Gold button
{
	character->RandomizeGold();
	goldAmount->Text = character->GetGold().ToString();
}


void CharaterSheetTool::MainPage::nameText_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = nameText->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	character->SetName(s);
}