/*  Shader Plus - plug-in for Carrara
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
#ifndef __SelectiveLighting__
#define __SelectiveLighting__
  
#if CP_PRAGMA_ONCE
#pragma once
#endif

#include "SelectiveLightingDef.h"
#include "BasicShader.h"
#include "copyright.h"
#include "IShComponent.h"
#include "I3dShScene.h"

struct SelectiveLightingPublicData{
	int32 lEffect;
	TMCDynamicString sList;
	boolean bAllowAmbient;
	boolean bAllowGI;
	TMCCountedPtr<IShParameterComponent> param;	
	};

enum SelectiveLightingEffect {sePassThru = 0, seExclude = 1, seInclude = 2};


//MCDEFINE_GUID2(CLSID_SelectiveLighting, R_CLSID_SelectiveLighting);
extern const MCGUID CLSID_SelectiveLighting;


class SelectiveLighting : public TBasicShader {
	public:
		SelectiveLighting();
		STANDARD_RELEASE;
		virtual int32   MCCOMAPI GetParamsBufferSize    ()
			const        { return sizeof(SelectiveLightingPublicData); }
		virtual void*			MCCOMAPI    GetExtensionDataBuffer();
		virtual MCCOMErr		MCCOMAPI	ExtensionDataChanged();
		virtual boolean			MCCOMAPI    IsEqualTo(I3DExShader* aShader);  
		virtual MCCOMErr		MCCOMAPI	GetShadingFlags(ShadingFlags& theFlags);
		virtual EShaderOutput	MCCOMAPI	GetImplementedOutput(); 
		virtual boolean			MCCOMAPI	HasExplicitLightingModel			(const LightingContext& lightingContext);
#if VERSIONNUMBER >= 0x050000
		virtual void			MCCOMAPI	CalculateDirectLighting(LightingDetail& result,const LightingContext&	lightingContext);
#if VERSIONNUMBER >= 0x070000
		virtual void MCCOMAPI CalculateIndirectLighting(TMCColorRGB& indirectDiffuseColor, real& ambientOcclusionFactor, const LightingContext& lightingContext,const ShadingOut& shading);
		virtual MCCOMErr MCCOMAPI ShadeAndLight2(LightingDetail& result,const LightingContext& lightingContext,I3DShLightingModel* inDefaultLightingModel,TAbsorptionFunction* absorptionFunction);
#else
		virtual void			MCCOMAPI	CalculateIndirectLighting(TMCColorRGB& indirectDiffuseColor,const LightingContext&	lightingContext,const ShadingOut& shading);
		virtual MCCOMErr		MCCOMAPI	ShadeAndLight						(LightingDetail& result,const LightingContext& lightingContext, I3DShLightingModel* inDefaultLightingModel);
#endif
#else
		virtual void			CalculateDirectLighting(LightingDetail& result,const LightingContext&	lightingContext);
		virtual void			CalculateIndirectLighting(TMCColorRGB& indirectDiffuseColor,const LightingContext&	lightingContext,const ShadingOut& shading);
#endif
		virtual MCCOMErr		MCCOMAPI DoShade							(ShadingOut& result,ShadingIn& shadingIn);
		virtual boolean			MCCOMAPI WantsTransform						() { return false; };

	protected:
		SelectiveLightingPublicData fData;
		ShadingFlags ChildFlags;
		EShaderOutput ChildOutput;
		TMCCountedPtr<I3DExShader> shader;
		TMCCountedPtr<I3DShScene> scene;
#if VERSIONNUMBER >= 0x050000
			I3DShLightingModel* defaultlightingmodel;
#endif
	};

#endif