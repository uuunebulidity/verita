//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2025 $organization$
///
/// This software is provided by the author and contributors ``as is''
/// and any express or implied warranties, including, but not limited to,
/// the implied warranties of merchantability and fitness for a particular
/// purpose are disclaimed. In no event shall the author or contributors
/// be liable for any direct, indirect, incidental, special, exemplary,
/// or consequential damages (including, but not limited to, procurement
/// of substitute goods or services; loss of use, data, or profits; or
/// business interruption) however caused and on any theory of liability,
/// whether in contract, strict liability, or tort (including negligence
/// or otherwise) arising in any way out of the use of this software,
/// even if advised of the possibility of such damage.
///
///   File: ViewController.hh
///
/// Author: $author$
///   Date: 10/20/2025, 11/9/2025
//////////////////////////////////////////////////////////////////////////
//#import <UIKit/UIKit.h>
#include "uLucidity/UI/UIKit/UIKit.h"
#include "uLucidity/Application/uDentify/UI/UIKit/uDentifyThread.hh"

namespace uLucidity {
namespace Application {
namespace uDentify {
namespace UI {
namespace UIKit {

} /// namespace UIKit 
} /// namespace UI 
} /// namespace uDentify 
} /// namespace Application 
} /// namespace uLucidity 

@interface ViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITextField *User;
@property (weak, nonatomic) IBOutlet UITextField *Resource;
@property (weak, nonatomic) IBOutlet UITextField *Password;
@property (weak, nonatomic) IBOutlet UITextField *Value;

@property (weak, nonatomic) IBOutlet UIButton *Ok;
@property (weak, nonatomic) IBOutlet UIButton *Clear;
@property (weak, nonatomic) IBOutlet UIButton *Done;

- (IBAction)User:(id)sender;
- (IBAction)Resource:(id)sender;
- (IBAction)Password:(id)sender;
- (IBAction)Value:(id)sender;

- (IBAction)Ok:(id)sender;
- (IBAction)Clear:(id)sender;
- (IBAction)Done:(id)sender;

@property (assign) BOOL valueUnset;
@property (assign) BOOL threadDone;
@property (strong, nonatomic) uDentifyThread *thread;
///////////////////////////////////////////////////////////////////////
/// onThreadWillStart
- (void)onThreadWillStart:(NSThread*)thread;
///////////////////////////////////////////////////////////////////////
/// onThreadFnished
- (void)onThreadFnished:(NSThread*)thread;
///////////////////////////////////////////////////////////////////////
/// onThreadResult
- (void)onThreadResult:(NSString*)result;
@end
