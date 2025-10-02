#pragma once

#include "ofSoundBaseTypes.h"
#include "ofSoundBuffer.h"
#include "ofConstants.h"

typedef unsigned int RtAudioStreamStatus;
class RtAudio;

class ofRtAudioSoundStream : public ofBaseSoundStream {
public:
	ofRtAudioSoundStream();
	~ofRtAudioSoundStream();

	std::vector<ofSoundDevice> getDeviceList(ofSoundDevice::Api api) const;

	void setInput(ofBaseSoundInput * soundInput);
	void setOutput(ofBaseSoundOutput * soundOutput);
	bool setup(const ofSoundStreamSettings & settings);

	void start();
	void stop();
	void close();

	uint64_t getTickCount() const;

	int getNumInputChannels() const;
	int getNumOutputChannels() const;
	int getSampleRate() const;
	int getBufferSize() const;
	ofSoundDevice getInDevice() const;
	ofSoundDevice getOutDevice() const;

	static std::string errorText;
	static bool gotError;

	bool getError() { return gotError; };
	std::string getErrorDescription() { return errorText; };

private:
	long unsigned long tickCount;
	std::shared_ptr<RtAudio>	audio;

	ofSoundBuffer inputBuffer;
	ofSoundBuffer outputBuffer;
	ofSoundStreamSettings settings;

	static int rtAudioCallback(void *outputBuffer, void *inputBuffer, unsigned int bufferSize, double streamTime, RtAudioStreamStatus status, void *data);

};
