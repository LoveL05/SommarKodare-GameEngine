#include "engine.h"
#include "updateable.h"

class SoundPlayer : public Startable {
public:
    SoundPlayer() {
    }

    ~SoundPlayer() {
        m_sound->StopSound();
        delete m_sound;
    }

    void onStart() override {
        this->m_sound = new Sound("assets/test_sound.wav");
        std::cout << m_sound << std::endl;
        m_sound->setupDevice();
        m_sound->playSound();
    }
   
private:
    Sound *m_sound;
};

int main(int argv, char** args)
{
    Engine engine = Engine("Title", 640, 480);

    SoundPlayer player = SoundPlayer();
    engine.AddStartable(&player);
    return engine.Run();
}
