/*  Toon! Pro - plug-in for Carrara
    Copyright (C) 2004 Eric Winemiller

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    
    http://digitalcarversguild.com/
    email: ewinemiller @ digitalcarversguild.com (remove space)
*/
#if CP_PRAGMA_ONCE
#pragma once 
#endif

#include "Basic3DCOMImplementations.h"
#include "SetCellLightingModelDef.h"
#include "BitField.h"
#include "I3DShFacetMesh.h"
#include "I3DShScene.h"
#include "I3DExModifier.h"
#include "ISceneSelection.h"
#include "IChangeManagement.h"
#include "PublicUtilities.h"
#include "ISceneDocument.h"
#include "copyright.h"
#include "cell.h"

// define the SceneOp CLSID

struct SetCellLightingModelPublicData{
	TVector2 vec2ShadowHighlight;
	int32 lLevels;
	real32 fShadowBrightness;
};


extern const MCGUID CLSID_SetCellLightingModel;

#if (VERSIONNUMBER >= 0x030000)
class SetCellLightingModelMenuPreparer : public TBasicMenuCallBack
{
public:
         virtual boolean MCCOMAPI SelfPrepareMenu(ISceneDocument* sceneDocument);
};
#endif

// SceneOp Object :
class SetCellLightingModel : public TBasicSceneCommand
{
	public :  
		SetCellLightingModel();
		STANDARD_RELEASE;
		virtual int32   MCCOMAPI GetParamsBufferSize    ()
			const        { return 0; }

		// IExDataExchanger methods :
		virtual int16	 MCCOMAPI GetResID				();
		virtual MCCOMErr MCCOMAPI HandleEvent(MessageID message, IMFResponder* source, void* data);
		virtual void*	 MCCOMAPI GetExtensionDataBuffer();
#if (VERSIONNUMBER >= 0x030000)
		virtual void	 MCCOMAPI GetMenuCallBack(ISelfPrepareMenuCallBack** callBack);
#else
		virtual boolean  MCCOMAPI SelfPrepareMenus			(ISceneDocument* sceneDocument);
#endif		
		virtual MCCOMErr MCCOMAPI Init						(ISceneDocument* sceneDocument);
		virtual MCCOMErr MCCOMAPI Prepare					();

		virtual boolean  MCCOMAPI CanUndo					();

		virtual boolean  MCCOMAPI Do						();
		virtual boolean  MCCOMAPI Undo						();
		virtual boolean  MCCOMAPI Redo						();

	private :
		SetCellLightingModelPublicData	fData;					
		TMCCountedPtr<ISceneDocument>	fSceneDocument;
		TMCCountedPtr<I3DShTreeElement>	fTree;
		TMCCountedPtr<I3DShScene>		fScene;

		TMCCountedPtr<ISceneSelection>	fSelection;
		TMCCountedPtr<ISceneSelection>	fCloneSelection;

		TMCCountedPtr<IChangeChannel>	fSelectionChannel;
		TMCCountedPtr<IChangeChannel>	fTreePropertyChannel;
		void ChangeLightingModel(I3DShMasterShader* masterShader);
};