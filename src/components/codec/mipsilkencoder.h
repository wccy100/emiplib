/*
    
  This file is a part of EMIPLIB, the EDM Media over IP Library.
  
  Copyright (C) 2006-2011  Hasselt University - Expertise Centre for
                      Digital Media (EDM) (http://www.edm.uhasselt.be)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  
  USA

*/

/**
 * \file mipsilkencoder.h
 */

#ifndef MIPSILKENCODER_H

#define MIPSILKENCODER_H

#include "mipconfig.h"

#ifdef MIPCONFIG_SUPPORT_SILK

#include "mipcomponent.h"
#include "miptime.h"
#include <list>

class MIPEncodedAudioMessage;

/** Compress audio using the Skype SILK codec.
 *  Using this component, raw 16 bit raw audio messages can be compressed using the SILK 
 *  codec. Messages generated by this component are encoded audio messages with subtype 
 *  MIPENCODEDAUDIOMESSAGE_TYPE_SILK.
 */
class EMIPLIB_IMPORTEXPORT MIPSILKEncoder : public MIPComponent
{
public:
	MIPSILKEncoder();
	~MIPSILKEncoder();

	/** Initializes the SILK encoder.
	 *  Initializes the SILK encoder.
	 *  \param inputSamplingRate The sampling rate of audio messages going into the component.
	 *  \param interval The interval contained in each incoming audio message. Should be a
	 *                  multiple of 20 ms, with a maximum value of 100 ms.
	 *  \param targetBitrate The target bitrate of the encoder.
	 *  \param encoderSamplingRate The maximum sampling rate used internally by the encoder.
	 */
	bool init(int inputSamplingRate, MIPTime interval, int targetBitrate, int encoderSamplingRate);

	/** De-initializes the SILK encoder. */
	bool destroy();

	bool push(const MIPComponentChain &chain, int64_t iteration, MIPMessage *pMsg);
	bool pull(const MIPComponentChain &chain, int64_t iteration, MIPMessage **pMsg);
private:
	void clearMessages();
	
	bool m_init;
	uint8_t *m_pState;
	void *m_pEncoderControlStruct;
	int m_inputSamplingRate;
	int m_maxInternalSamplingRate;
	int m_frameSize;
	int m_targetBitrate;
	int64_t m_prevIteration;

	std::list<MIPEncodedAudioMessage *> m_messages;
	std::list<MIPEncodedAudioMessage *>::const_iterator m_msgIt;
};	

#endif // MIPCONFIG_SUPPORT_SPEEX

#endif // MIPSPEEXENCODER_H

