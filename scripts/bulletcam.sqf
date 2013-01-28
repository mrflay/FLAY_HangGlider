_projectile = nearestobject [_this select 0,_this select 4];
//setacctime 0.2;
_camera = "camera" camCreate (getpos _projectile);
_camera cameraeffect ["internal", "back"];
while{alive _projectile && alive _camera}do
{
_camera camSetTarget _projectile;
_camera camSetRelPos [0,-13,1.2];
_camera camCommit 0;
sleep 0.01;
};
if(alive _camera)then{sleep 1};
_camera cameraeffect ["terminate", "back"];
camdestroy _camera;
//setacctime 1;