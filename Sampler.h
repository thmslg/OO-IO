#ifndef SAMPLER_H_
#define SAMPLER_H_

#include "Samplable.h"

//------------------------------------------------------------------------------------------------------------
//! This class is responsible for define an abstract view of a sampler.
//! The responsability of a sampler is to periodically pole a set of samplable object
//------------------------------------------------------------------------------------------------------------

class Sampler{

public:
	virtual ~Sampler(){};

	//--------------------------------------------------------------------------------------------------------
	//! \pre  /!\Sampling should be stopped
	//!	"SamplableToAdd" have to be ready to call "acquire" method, have to be thread safe
	//! \post Add reference to Samplable instance
	virtual bool AddSlowFrequencySamplable(Samplable * SamplableToAdd) = 0;

	//------------------------------------------------------------------------------------------------------------
	//! \pre  /!\Sampling should be stopped
	//!	"SamplableToAdd" have to be ready to call "acquire()" method, have to be thread safe
	//! \post Return true if operation succeed,
	//! 	return false else.
	virtual bool RemoveSlowFrequencySamplable(Samplable * SamplableToAdd)=0;

	//------------------------------------------------------------------------------------------------------------
	//! \pre /!\ Sampling should be stopped
	//!	"SamplableToAdd" have to be ready to call "acquire" method, have to be thread safe
	//! \post See parent
	virtual bool AddHighFrequencySamplable(Samplable * SamplableToAdd)=0;

	//------------------------------------------------------------------------------------------------------------
	//! \pre /!\ Sampling should be stopped
	//!	"SamplableToAdd" have to be ready to call "acquire()" method, have to be thread safe
	//! \post Return true if operation succeed,
	//! 	return false else.
	virtual bool RemoveHighFrequencySamplable(Samplable * SamplableToAdd)=0;

	//------------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post Now sampling is working, acquire() will be call with defined period
	virtual void StartSampling()=0;

	//------------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post Stop sampling
	virtual void StopSampling()=0;
};



#endif /* SAMPLER_H_ */
