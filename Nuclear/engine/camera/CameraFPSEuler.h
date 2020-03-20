

namespace Camera {
	class CameraFPSEuler {
		public:
			void UpdateView();
			void KeyPressed(const unsigned char key);
			void MouseMove(int x, int y, int width, int height);
			void MousePressed(int button, int state, int x, int y);
			const double speed = 0.12f; //how fast we move
	};
}
