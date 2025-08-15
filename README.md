# MVVM UnrealEngine
MVVM plugin pattern simple example using Puzzle Template.

![Puzzle game](/Images/MVVM_Puzzle.png)

https://dev.epicgames.com/documentation/en-us/unreal-engine/umg-viewmodel-for-unreal-engine

![Unreal Engine scheme](/Images/viewmodelworkflow.png)

User -> Interacts with UI -> Widget sends update back to bound MVVM variable ->ViewModel sends update back to actor/game
object.

Actor/Game object sends changes to variables in MVVM -> ViewModel updates bound variables using FieldNotify ->
Widget displays updated information to user.