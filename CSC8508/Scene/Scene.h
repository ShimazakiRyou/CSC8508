﻿//
// Contributors: Alfie
//

#ifndef SCENE_H
#define SCENE_H

class Scene {
public:
    virtual ~Scene() = default;

    /**
     * Called when the SceneManager has just changed the current Scene to this one.
     */
    virtual void OnLoad() { }

    /**
     * Called every tick when this Scene is the SceneManager's current scene.
     * @param dt Delta time: The change in time from the last tick in seconds
     */
    virtual void Update(float dt) { }

    /**
     * Called when the SceneManager has just changed the current scene away from this one.
     */
    virtual void OnUnload() { }
};

#endif //SCENE_H
