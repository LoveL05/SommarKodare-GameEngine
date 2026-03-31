#include <Engine.h>
#include <Updateable.h>

class SoundPlayer : public Startable {
public:
    SoundPlayer() {
    }

    ~SoundPlayer() {
        m_sound->StopSound();
        delete m_sound;
    }

    void OnStart() override {
        this->m_sound = new Sound("waluigi.wav");
        std::cout << m_sound << std::endl;
        m_sound->SetupDevice();
        m_sound->PlaySound();
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
