#![windows_subsystem = "console"]

mod bootstrap;

fn main() -> windows::Result<()> {
    bootstrap::initialize()
        .and_then(|_| {
            println!("[*] Bootstrap successful.");
            Ok(())
        })
        .and_then(|_| bootstrap::uninitialize())
}
