#ifndef _RTEMULTIPLAYERGAME_
#define _RTEMULTIPLAYERGAME_

//////////////////////////////////////////////////////////////////////////////////////////
// File:            MultiplayerGame.h
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     
// Project:         Retro Terrain Engine
// Author(s):       


//////////////////////////////////////////////////////////////////////////////////////////
// Inclusions of header files

#include "RTETools.h"
#include "ActivityMan.h"

namespace RTE
{

	class MultiplayerGameGUI;
	class GUIScreen;
	class GUIInput;
	class GUIControlManager;
	class GUICollectionBox;
	class GUITab;
	class GUIListBox;
	class GUITextBox;
	class GUIButton;
	class GUILabel;
	class GUIComboBox;


	//////////////////////////////////////////////////////////////////////////////////////////
	// Class:           MultiplayerGame
	//////////////////////////////////////////////////////////////////////////////////////////
	// Description:     Activity for editing scenes.
	// Parent(s):       EditorActivity.
	// Class history:   8/30/2007 MultiplayerGame created, inheriting directly from Activity.
	//                  9/17/2007 Spliced out and made to derive from EditorActivty

	class MultiplayerGame :
	public Activity
	{

		//////////////////////////////////////////////////////////////////////////////////////////
		// Public member variable, method and friend function declarations

	public:

		// Concrete allocation and cloning definitions
		EntityAllocation(MultiplayerGame)
		SerializableOverrideMethods
		ClassInfoGetters


		enum MultiplayerGameMode
		{
			SETUP,
			CONNECTION,
			GAMEPLAY
		};


		//////////////////////////////////////////////////////////////////////////////////////////
		// Constructor:     MultiplayerGame
		//////////////////////////////////////////////////////////////////////////////////////////
		// Description:     Constructor method used to instantiate a MultiplayerGame object in system
		//                  memory. Create() should be called before using the object.
		// Arguments:       None.

		MultiplayerGame() { Clear(); }


		//////////////////////////////////////////////////////////////////////////////////////////
		// Destructor:      ~MultiplayerGame
		//////////////////////////////////////////////////////////////////////////////////////////
		// Description:     Destructor method used to clean up a MultiplayerGame object before deletion
		//                  from system memory.
		// Arguments:       None.

		virtual ~MultiplayerGame() { Destroy(true); }


		//////////////////////////////////////////////////////////////////////////////////////////
		// Virtual method:  Create
		//////////////////////////////////////////////////////////////////////////////////////////
		// Description:     Makes the MultiplayerGame object ready for use.
		// Arguments:       None.
		// Return value:    An error return value signaling sucess or any particular failure.
		//                  Anything below 0 is an error signal.

		virtual int Create();


		//////////////////////////////////////////////////////////////////////////////////////////
		// Virtual method:  Create
		//////////////////////////////////////////////////////////////////////////////////////////
		// Description:     Creates a MultiplayerGame to be identical to another, by deep copy.
		// Arguments:       A reference to the MultiplayerGame to deep copy.
		// Return value:    An error return value signaling sucess or any particular failure.
		//                  Anything below 0 is an error signal.

		virtual int Create(const MultiplayerGame &reference);


		//////////////////////////////////////////////////////////////////////////////////////////
		// Virtual method:  Reset
		//////////////////////////////////////////////////////////////////////////////////////////
		// Description:     Resets the entire MultiplayerGame, including its inherited members, to their
		//                  default settings or values.
		// Arguments:       None.
		// Return value:    None.

		virtual void Reset() { Clear(); Activity::Reset(); }


		//////////////////////////////////////////////////////////////////////////////////////////
		// Virtual method:  Destroy
		//////////////////////////////////////////////////////////////////////////////////////////
		// Description:     Destroys and resets (through Clear()) the MultiplayerGame object.
		// Arguments:       Whether to only destroy the members defined in this derived class, or
		//                  to destroy all inherited members also.
		// Return value:    None.

		virtual void Destroy(bool notInherited = false);


		//////////////////////////////////////////////////////////////////////////////////////////
		// Virtual method:  Start
		//////////////////////////////////////////////////////////////////////////////////////////
		// Description:     Officially starts the game accroding to parameters previously set.
		// Arguments:       None.
		// Return value:    An error return value signaling sucess or any particular failure.
		//                  Anything below 0 is an error signal.

		virtual int Start();


		//////////////////////////////////////////////////////////////////////////////////////////
		// Virtual method:  Pause
		//////////////////////////////////////////////////////////////////////////////////////////
		// Description:     Pauses and unpauses the game.
		// Arguments:       Whether to pause the game or not.
		// Return value:    None.

		virtual void Pause(bool pause = true);


		//////////////////////////////////////////////////////////////////////////////////////////
		// Virtual method:  End
		//////////////////////////////////////////////////////////////////////////////////////////
		// Description:     Forces the current game's end.
		// Arguments:       None.
		// Return value:    None.

		virtual void End();


		//////////////////////////////////////////////////////////////////////////////////////////
		// Virtual method:  Update
		//////////////////////////////////////////////////////////////////////////////////////////
		// Description:     Updates the state of this ActivityMan. Supposed to be done every frame
		//                  before drawing.
		// Arguments:       None.
		// Return value:    None.

		virtual void Update();


		//////////////////////////////////////////////////////////////////////////////////////////
		// Virtual method:  DrawGUI
		//////////////////////////////////////////////////////////////////////////////////////////
		// Description:     Draws the currently active GUI of a screen to a BITMAP of choice.
		// Arguments:       A pointer to a screen-sized BITMAP to draw on.
		//                  The absolute position of the target bitmap's upper left corner in the scene.
		//                  Which screen's GUI to draw onto the bitmap.
		// Return value:    None.

		virtual void DrawGUI(BITMAP *pTargetBitmap, const Vector &targetPos = Vector(), int which = 0);


		//////////////////////////////////////////////////////////////////////////////////////////
		// Virtual method:  Draw
		//////////////////////////////////////////////////////////////////////////////////////////
		// Description:     Draws this ActivityMan's current graphical representation to a
		//                  BITMAP of choice. This includes all game-related graphics.
		// Arguments:       A pointer to a BITMAP to draw on. OWNERSHIP IS NOT TRANSFERRED!
		//                  The absolute position of the target bitmap's upper left corner in the scene.
		// Return value:    None.

		virtual void Draw(BITMAP *pTargetBitmap, const Vector &targetPos = Vector());


		//////////////////////////////////////////////////////////////////////////////////////////
		// Protected member variable and method declarations

	protected:
		// Member variables
		static Entity::ClassInfo m_sClass;

		// The editor GUI
		//MultiplayerGameGUI *m_pEditorGUI;

		// 
		GUITextBox *m_pServerNameTextBox;

		GUITextBox *m_pPlayerNameTextBox;

		GUIButton *m_pConnectButton;



		GUITextBox *m_pNATServiceServerNameTextBox;

		GUITextBox *m_pNATServerNameTextBox;

		GUITextBox *m_pNATServerPasswordTextBox;

		GUIButton *m_pConnectNATButton;



		GUILabel *m_pStatusLabel;

		// GUI Screen for use by the GUI dialog boxes. Owned
		GUIScreen *m_pGUIScreen;
		// Input controller for he dialog box gui.  Owned
		GUIInput *m_pGUIInput;
		// The control manager which holds all the gui elements for the dialog boxes.  Owned
		GUIControlManager *m_pGUIController;
		// Current state of the activity
		MultiplayerGameMode m_Mode;

		// Timer to watchdog connection states and abort connection if nothing happened
		Timer m_ConnectionWaitTimer;

		// Last music file being player, used to recover playback state after pause
		std::string m_LastMusic;

		// Position of music being played, used to recover playback state after pause
		double m_LastMusicPos;


		//////////////////////////////////////////////////////////////////////////////////////////
		// Private member variable and method declarations

	private:

		//////////////////////////////////////////////////////////////////////////////////////////
		// Method:          Clear
		//////////////////////////////////////////////////////////////////////////////////////////
		// Description:     Clears all the member variables of this Activity, effectively
		//                  resetting the members of this abstraction level only.
		// Arguments:       None.
		// Return value:    None.

		void Clear();
	};

} // namespace RTE

#endif // File
