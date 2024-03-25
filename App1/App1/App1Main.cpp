#include "pch.h"
#include "App1Main.h"
#include "Common\DirectXHelper.h"

using namespace App1;
using namespace Windows::Foundation;
using namespace Windows::System::Threading;
using namespace Concurrency;

// Pour plus d'informations sur le mod�le Application DirectX�12, consultez la page https://go.microsoft.com/fwlink/?LinkID=613670&clcid=0x409

// Charge et initialise les actifs de l'application durant son chargement.
App1Main::App1Main()
{
	// TODO: modifiez les param�tres de minuterie si vous voulez utiliser autre chose que le mode timestep variable par d�faut.
	// par exemple, pour une logique de mise � jour timestep fixe de 60�FPS, appelez�:
	/*
	m_timer.SetFixedTimeStep(true)�;
	m_timer.SetTargetElapsedSeconds(1.0 / 60)�;
	*/
}

// Cr�e et initialise les convertisseurs.
void App1Main::CreateRenderers(const std::shared_ptr<DX::DeviceResources>& deviceResources)
{
	// TODO: remplacez ceci par l'initialisation du contenu de votre application.
	m_sceneRenderer = std::unique_ptr<Sample3DSceneRenderer>(new Sample3DSceneRenderer(deviceResources));

	OnWindowSizeChanged();
}

// Met � jour l'�tat de l'application une fois par frame.
void App1Main::Update()
{
	// Mettre � jour les objets de sc�ne.
	m_timer.Tick([&]()
	{
		// TODO: remplacez ceci par vos fonctions de mise � jour de contenu d'application.
		m_sceneRenderer->Update(m_timer);
	});
}

// Affiche le frame actuel en fonction de l'�tat actuel de l'application.
// Retourne true si le frame a �t� rendu et est pr�t � �tre affich�.
bool App1Main::Render()
{
	// N'essayez d'afficher aucun �l�ment avant la premi�re mise � jour.
	if (m_timer.GetFrameCount() == 0)
	{
		return false;
	}

	// Afficher les objets de sc�ne.
	// TODO: remplacez ceci par vos fonctions de rendu de contenu d'application.
	return m_sceneRenderer->Render();
}

// Met � jour l'�tat de l'application quand la taille de la fen�tre change (par exemple, durant le changement d'orientation de l'appareil)
void App1Main::OnWindowSizeChanged()
{
	// TODO: remplacez ceci par l'initialisation du contenu de votre application en fonction de la taille.
	m_sceneRenderer->CreateWindowSizeDependentResources();
}

// Indique � l'application qu'elle est suspendue.
void App1Main::OnSuspending()
{
	// TODO: remplacez ceci par la logique de suspension de votre application.

	// La gestion de la dur�e de vie des processus peut terminer les applications suspendues � tout moment. Il est donc
	// conseill� d'enregistrer les �tats qui permettent � l'application de red�marrer l� o� elle s'est arr�t�e.

	m_sceneRenderer->SaveState();

	// Si votre application utilise les allocations de m�moire vid�o, qui sont faciles � recr�er,
	// lib�rez la m�moire pour la mettre � disposition des autres applications.
}

// Indique � l'application qu'elle n'est plus suspendue.
void App1Main::OnResuming()
{
	// TODO: remplacez ceci par la logique de reprise de votre application.
}

// Avertit les convertisseurs que les ressources du p�riph�rique doivent �tre lib�r�es.
void App1Main::OnDeviceRemoved()
{
	// TODO: enregistrez l'�tat n�cessaire de l'application ou du convertisseur, puis lib�rez le convertisseur
	// et ses ressources qui ne sont plus valides.
	m_sceneRenderer->SaveState();
	m_sceneRenderer = nullptr;
}
